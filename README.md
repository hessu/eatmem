
eatmem
---------

Eats N megabytes of memory, and writes to it to keep it allocated.  Run a
couple copies eating (together) more memory than you really have, and you'll
have a nice swapping effect.

Useful for stress testing VM and IO.


Building
-----------

    gcc -Wall -o eatmem eatmem.c


Usage
--------

   ./eatmem <megabytes> <rounds>

For example, 1000 megabytes and 100 write rounds:

    ./eatmem 1000 100

On each round, eatmem does two passes of writing, using memset().


License
----------

Free software - if it breaks, you get to keep both pieces.

BSD 2-clause, or EVVKTVH license, as you prefer.



Heikki Hannikainen