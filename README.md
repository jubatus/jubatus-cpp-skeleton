Skelton of Jubatus Client Application in C++
============================================

Requirements
------------

* Jubatus 0.3.3 (server & client headers)
* pficommon (with development headers)
* msgpack (with development headers)

Usage
-----

To build a client program, run:

```
$ ./waf configure
$ ./waf build
```

To test the client, run:

```
$ jubarecommender &
$ build/client
```

Now, write your own code in `client.cpp`, then rebuild and run the client again.
