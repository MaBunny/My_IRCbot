# My_IRCbot
Welcome to My_IRCBot bot page,a custom IRC bot I am making for fun and the love of coding.

This bot is in its primary stages,and unless I get lots of time to dedicated to this project,it will probably take a couple of months(maybe some years) to finish it.

COMPILING
---------

This project is primarily made on Debian Jessie,but it can be build on other distros if the following packages are available:-
i)GNU C++ Compiler(v4.9 or greater)

ii)libstdc++(v4.9 or greater)

Plus any associative files for those 2 packages.

In the terminalopened from the repo folder,just type this(note: the present state of the program centres around the Config object,though later it could be changed easily changed as per the project advances):-

$: sh compile-without-flags.sh

This should create an executable,which you can then run and see for yourself.

COMPILING WITH DEBUGGING OPTIONS
--------------------------------

This is useful for debugging purposes only,so try the above way.Or else the previous two packages will be required besides these:-

i)GNU Debugger(gdb)

ii)GNU Debugger Server(gdb-server)

In the terminal opened from the repo folder,just type this line:-

$: sh gdb-compile.sh

That should make the code both into an object file and make a debugging executable.Then in the terminal type this:-

$: gdb -q
$: file a.out

Then you can start your debugging process.A quick guide to the GCC debugger is
this:http://www.delorie.com/gnu/docs/gdb/gdb_toc.html#SEC_Contents



