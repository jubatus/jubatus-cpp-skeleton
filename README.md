Skeleton of Jubatus Client Application in C++
==============================================

Requirements
------------

* Jubatus 0.5.0+ (server & client headers)
* msgpack (with development headers)
* jubatus-mpio (with development headers)
* jubatus-msgpack-rpc (with development headers)

Usage
-----

To build a client program, run:

```
$ ./waf configure
$ ./waf build
```

To test the client, run:

```
$ jubarecommender --configpath config.json &
$ build/client
```

Now, write your own code in `client.cpp`, then rebuild and run the client again.
