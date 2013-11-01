#include <iostream>

#include <jubatus/client.hpp>

using namespace std;

const string HOST = "localhost";
const int    PORT = 9199;
const string NAME = "";

int main(int argc, char* argv[]) {
  jubatus::recommender::client::recommender r(HOST, PORT, NAME, 5);

  {
    jubatus::client::common::datum d;
    d.add_number("movie_A", 5);
    d.add_number("movie_B", 2);
    d.add_number("movie_C", 3);
    r.update_row("user01", d);
  }

  {
    jubatus::client::common::datum d;
    d.add_number("movie_A", 2);
    d.add_number("movie_B", 5);
    d.add_number("movie_C", 1);
    r.update_row("user02", d);
  }

  {
    jubatus::client::common::datum d;
    d.add_number("movie_A", 5);
    d.add_number("movie_B", 1);
    d.add_number("movie_C", 4);
    r.update_row("user03", d);
  }

  vector<string> rows = r.get_all_rows();
  for (size_t i = 0; i < rows.size(); i++) {
    string id = rows[i];
    std::vector<jubatus::recommender::id_with_score> result;
    result = r.similar_row_from_id(id, 3);
    cout << id << " is similar to: " << endl;
    cout << "  ";
    for (size_t n = 0; n < result.size(); n++) {
      cout << result[n].id << " (" << result[n].score << "), ";
    }
    cout << endl;
  }
}
