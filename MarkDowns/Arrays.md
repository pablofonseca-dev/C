# Harvard CS50 Week 2

## Notes

This is a special flag that we'll tease apart
in just a couple of minutes, an argument to Clang that tells it to link in, so to speak, link in all of the zeros and ones from CS50's library.

### Compiling Process

#### 1. Pre-Processing

So let's take a look at pre-processing.
This is a term of art in programming that refers to the following.
When you have source code that looks like this,
you have a couple of lines at the top that
say hash include two files, two library files.
Well, when you actually run Clang or you induce
Clang to run by using Make, what happens is those lines
that start with the hash symbol are actually sort of replaced
with the actual contents of that file.
So instead of this code remaining include CS50.h,
literally what Clang does is go into CS50.h,
grab the relevant lines of code, and essentially copy-paste them
into your file, hello.c or whatever it's called.
The next line here, standard io.h similarly
gets replaced with whatever the lines of code are in that file, standard io.h.
Doesn't matter to us what they are, but they look a little something like this,
though I've simplified on the slide here.
And there's a whole bunch of other stuff above and below those lines
certainly in those files.
What then happens after that?
Well, compiling, even though this is the word
we use and we'll continue using to describe
taking source code to machine code, it's actually a more precise step than that.
When a computer-- when a program is compiled,
it technically starts like this after having been pre-processed-- again,
that was step 1. **What then happens after that?**

### 2. Compiling

Well, compiling, even though this is the word
we use and we'll continue using to describe
taking source code to machine code, it's actually a more precise step than that.
When a computer-- when a program is compiled,
it technically starts like this after having been pre-processed-- again,
that was step 1.
This code is then converted by a compiler,
like Clang, to something that looks even scarier than C. This is something
called assembly code, and you can actually
take entire courses on assembly code.
And it wasn't all that many decades ago that humans were manually
programming code that looked like this, so it wasn't quite zeros and ones.
But my god, C is looking pretty good now,
if this is the alternative language back in the day.
So this is an example of assembly language.
But even though it's pretty arcane looking,
if I highlight in yellow a few characteristics,
there's some things that are familiar.
Main is up here.
Get string is down here.
**Printf** is down here.
So when your code is compiled by Clang, it goes from your source code in C
to this intermediate step assembly code, and that's just
a little closer to what the CPU, the brain of your computer,
actually understands.
In fact, now highlighted in yellow are what are called instructions.
So if you've ever heard of Intel or AMD or a bunch of companies
that make CPUs, central processing units,
the brains of a computer, what those CPUs understand
is these very, very low level operations like this.
And these relate to moving things around in memory and copying things
and reading things and putting things onto the screen.
But much more arcanely than C is.
But again, we don't have to care about this,
because Clang does all of this for us.

### 3. Assembling

But once you're at that point of having assembly code,
you need to get it to machine code the actual zeros and ones.
And that's where Clang does what's called assembling.
There's another part of Clang, like some built-in functionality, that
takes as input that assembly code and converts it
from this to the zeros and ones that we talked about in week 0.

### 4. Linking
For a program like hello.c, which involved a few different files.
For instance, this code again involved my code that we wrote last week.
It involves the CS50 library, which the staff wrote years ago.
And it involves standard io.h.
That's yet another file.
That's like three different files that Clang frankly has to compile for you.
Now it would be super tedious if we had to run Clang like three times
to do all this compilation.
Thankfully we don't.
It all happens automatically.
So the last step in compiling a program after it's been pre-processed,
after it's been compiled, after it's been assembled,
is to combine all of the zeros and ones from the files involved
into one big file, like Hello or a.out.
So if hello.c started as source code, as did CS50.C, somewhere on the computer's
hard drive, as did Standard IO.C, somewhere on the computer's hard drive,
turns out the printf is actually in its own file within Standard IO.
the library.
But these are the three files involved for the program I just described.
So once we actually go ahead and assemble this one,
it becomes a whole bunch of zeros and ones.
We assemble this one, a whole bunch of zeros and ones.
This one, a whole bunch of zeros and ones.
That's like three separate files that then
get linked together, sort of commingled, into one big file called Hello,
or called a.out.

## Debugging

### Where did the word debug come from?

All right.
So beyond that, I'm sure you've encountered now, after just one
week, bugs in your software.
And in fact, one of the greatest skills you can acquire from programming class
is not only how to write code, but how to debug code, most likely your own.
And if you've ever wondered where this phrase comes from,
this notion of debugging, so this is actually part of the mythology.
So this is actually a notebook kept by Grace Hopper,
a very famous computer scientist, working years ago with some colleagues
on what was called the Mark 2 system.
If you've ever walked through Harvard Science Center,
there's a big part of a machine in the ground floor of the Science Center.
That's the Mark 1, the precursor.
Well, the Mark 2 at some point was discovered
as having literally a bug inside of it, which was causing a problem.
A moth of sorts.
And Grace Hopper actually made this record here, if we zoom in,
the first actual case of bug being found.
And even though other people had used the expression bug
before to refer to mistakes or problems in systems,
this is really sort of the lore that folks in computer science look back on.
So bugs are just mistakes in programs, things that you surely did not intend.
And we'll consider today now how we can empower you,
much more so than this past week, to solve your own problems
and actually debug your software.

## Tools Introduced

* help50 **correctness**
* printf **correctness, not necessary now**
* debug50 **correctness**
* check50 **correctness**
* style50 **style**

## Check50 and Real World Test

Whenever you work for a company or write software, part of that process
is typically not just to write the code that solves your problem,
but to write tests that make sure that your own code is correct, especially
so that if you add features to your programs down the road or someone else
tries to add features to your code, they and you don't break it--
you're constantly have a capability to make sure your code is still
working as expected.
So while we do use it in academic context to score problems sets,
it's fundamentally representative of a real-world process
of testing one's own code repeatedly.

## Rubber Duck Debugging

I have literally, and I'm sure many of the TF's and TA's have, solved code
while falling asleep, because there, you're sort of thoughtfully
thinking through what it is you did, what it is you're trying to do.
But undoubtedly, it helps to talk through your problems some time.
And there's this other term of art in computer science called
rubber duck debugging.
The idea being that if you don't have a TF at your side
or CA at your side or roommate who has any idea what you're talking about when
it comes to programming, you can have one of these little things on your desk
that you can literally, probably with the door
closed, start talking to, to explain to the duck, just like you would
a teaching fellow, what it is you think your code is doing, walking through
it line-by-line verbally, until hopefully, you
have that self-induced aha moment, like oh, wait a minute,
it's supposed to be 10 not 11, at which point,
you discretely put the duck back down and go about your work.
But it is meant to be this proxy for just
a very deliberate thoughtful process to which everyone is welcome.
You're welcome to take a duck today on your way out
and we have lots more tutorials and office hours,
because this is not enough here today.
This is just because it exists.
But the goal with rubber duck debugging is just that additional human mechanism
for solving problems by taking the emphasis off of tools
and putting it really back on the human.
So if a little socially awkwardly, consider
deploying that tool as needed as well.
So that's all focusing on correctness and style.

## Array Structures

An array is something that allow us to solve a problem.

Now we have seen this data types:

* **bool**   1 byte ->  8 bits
* **char**   1 byte
* **int**    4 bytes
* **float**  4 bytes -> 32 bits
* **long**   8 bytes
* **double** 8 bytes -> 64 bits
* **string** ? bytes
