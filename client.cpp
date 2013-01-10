#include <iostream>

#include <jubatus/client.hpp>

using namespace std;

const string HOST = "localhost";
const int    PORT = 9199;
const string NAME = "";

int main(int argc, char* argv[]){
    jubatus::recommender::client::recommender r(HOST, PORT, 5);
    jubatus::recommender::datum d;

    d.num_values.push_back(make_pair("movie_A", 5));
    d.num_values.push_back(make_pair("movie_B", 2));
    d.num_values.push_back(make_pair("movie_C", 3));
    r.update_row(NAME, "user01", d);
    d.num_values.clear();

    d.num_values.push_back(make_pair("movie_A", 2));
    d.num_values.push_back(make_pair("movie_B", 5));
    d.num_values.push_back(make_pair("movie_C", 1));
    r.update_row(NAME, "user02", d);
    d.num_values.clear();

    d.num_values.push_back(make_pair("movie_A", 5));
    d.num_values.push_back(make_pair("movie_B", 1));
    d.num_values.push_back(make_pair("movie_C", 4));
    r.update_row(NAME, "user03", d);
    d.num_values.clear();

    vector<string> rows = r.get_all_rows(NAME);
    for (size_t i = 0; i < rows.size(); i++) {
        string id = rows[i];
        jubatus::recommender::similar_result result;
        result = r.similar_row_from_id(NAME, id, 3);
        cout << id << " is similar to: " << endl;
        cout << "  ";
        for (size_t n = 0; n < result.size(); n++) {
            cout << result[n].first << " (" << result[n].second << "), ";
        }
        cout << endl;
    }
}
