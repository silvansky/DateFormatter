# DateFormatter is a UNIX command line utility for formatting current date

DateFormatter accepts two arguments: a format string and a separator.

Usage example:

```
./dateformatter "DD MMM YY" "-"
06-Apr-13
```

Supported date formatting patterns:

DD - day number (with leading zero)
MM - month number (with leading zero)
MMM - short month name (Jan, Feb, Mar, etc)
YY - two last digits of the year
YYYY - full year

Unit tests based on [CxxTest](https://github.com/CxxTest/cxxtest) also included. To run them you can run these commands:

make tests / ./runtests.sh - just run tests and print out a success rate.

make tests-verbose / ./runtests.sh -v - run tests and print out a success rate and some tracing information.

Note that CxxTest is added as git submodule, so after cloning a repo you should run these commands:

```
git submodule init
git submodule update
```

The source code of DateFormatter is distributed under [MIT License](http://en.wikipedia.org/wiki/MIT_License). See file LICENSE for more information.