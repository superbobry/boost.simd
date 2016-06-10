
Tutorials {#tutorials}
=========

@tableofcontents

@section tutorial-objectives Objectives

----------------------------------------------------------------------------------------------------
These tutorials present the general principles of **Boost.SIMD**:

  + using the pack abstraction
  + compiling **Boost.SIMD** code
  + using _SIMD_ specific idioms like reduction, branching or shuffling
  + vectorizing code using the Standard Template Library
  + _SIMD_ runtime dispatching

For this tutorial, we will assume the use of a 128 bit wide _SIMD_ extensions (such as SSE or Altivec). Depending on your actual architecture, the output of the various tutorial applications may vary.

@section tutorial-kernel A Simple SIMD Kernel

----------------------------------------------------------------------------------------------------
Here is a simple program demonstrating some basic **Boost.SIMD** functionality.

@snippet helloworld.cpp hello

This small code sample presents the basic building blocks of **Boost.SIMD**, which we explain below.

## The **Boost.SIMD** namespace

When using a **Boost.SIMD** type or function, it is necessary to use the boost::simd namespace. In order to simplify the code, you may wish to give it an alias:

@snippet helloworld.cpp hello-namespace

This avoids having to type the full namespace every time you use a **Boost.SIMD** function.

## The boost::simd::pack abstraction

The basis of any code using **Boost.SIMD** is the boost::simd::pack class included by

@snippet helloworld.cpp hello-include-pack

The pack may be considered analagous to an _SIMD_ register on your (or any other) machine. Operations performed on packs - from elementary operations like addition to full functions like sin(x) - will be performed using _SIMD_ registers and operations if supported by your hardware. As shown in the following example, data must still be loaded into and stored from these registers.

## Is it better practice to use the pack as an array?

The main element of **Boost.SIMD** is the boost::simd::pack class, accessible through the boost/simd/pack.hpp header file. `pack<T,N>` is an abstraction over a block of `N` elements of type `T`, quite similar to `std::array`. The main semantic difference is that boost::simd::pack is implemented as the best hardware specific type able to store this amount of data which may be a simple scalar array, a single _SIMD_ register or a tuple of _SIMD_ registers depending on `N` and `T`.

## Constructing a boost::simd::pack

One way to construct a boost::simd::pack is to simply declare (default-construct) it. Such boost::simd::pack are not zero-initialized and thus may contain arbitrary values.

@snippet helloworld.cpp hello-def-ctor

Another way to construct a boost::simd::pack is to fill it with a single value. This so-called splatting constructor takes one scalar value and replicates it in all elements of the pack.

@snippet helloworld.cpp hello-splat-ctor

You may also perform the splat explicitly if you wish

@snippet helloworld.cpp hello-splat-explicit

Finally, you can also initializes every element of the boost::simd::pack itself by enumerating them.

@snippet helloworld.cpp hello-enum-ctor

Note that this constructor makes the strong assumption that the size of your boost::simd::pack is correct. Unless required, it's generally a good idea to try to avoid depending on a fixed size for boost::simd::pack unless
the algorithm requires it. The splat function is recommended over this usage wherenever possible.

## Operations on boost::simd::pack

Once initialized, operations on boost::simd::pack instances are similar to operations on scalar as all operators and standard library math functions are provided. A simple pattern make those functions and operators available: if you need to use an arbitrary function or operator like boost::simd::plus, you need to include the boost/simd/function/plus.hpp file. We do the same for boost::simd::splat and boost::simd::multiplies.

@snippet helloworld.cpp hello-ops

Note that type checking is stricter than one may expect when scalar and _SIMD_ values are mixed. **Boost.SIMD** only allows mixing types of the same scalar kind, i.e reals with reals or integers with integers. Here, we have to multiply by `2.f` and not simply `2`.

Finally, we display the boost::simd::pack content by using the `operator<<` overload provided by the boost/simd/io.hpp header file.

@snippet helloworld.cpp hello-io

## Compiling the code

The compilation of the code is rather straight-forward: just pass the path to **Boost.SIMD** and use your compiler options to activate the desired _SIMD_ extension support - in this case the sse2 extension triggered by `-msse2`. Due to the way **Boost.SIMD** is structured, it is highly recommended to use the `-O3` flag to take full advantage of compiler optimizations.

For example, on `gcc`:

`g++ my_code.cpp -O3 -o my_code -I/path/to/boost.simd/ -msse2`

Some compilers, like Microsoft Visual Studio, don't propagate the fact a given architecture specific option is triggered. In this case, you need to also defines an architecture specific preprocessor symbol.

## The result

We can then have a look at the program's output which should look like:

`{42,42,42,42}`

Now, let's have a look at the generated assembly code (using `objdump` for example) :

@code{.objdump}
movaps 0x300(%rip),%xmm0
addps  0x2e6(%rip),%xmm0
mulps  0x2ff(%rip),%xmm0
movaps %xmm0,(%rsp)
@endcode

This shows that we correctly emitted `*ps` instructions. Note how the abstractions introduced by boost::simd::pack don't incur any penalty.


@section tutorial-sum Sum of Arrays

----------------------------------------------------------------------------------------------------

This tutorial presents the different ways to fill and use a boost::simd::pack in a more realistic use case than above.

The following methods will show different ways to vectorize the following scalar code computing the difference between an array and a constant.

@snippet arrayplus.cpp sum-scalar

In order to take advantage of **Boost.SIMD**, we will use the boost::simd::load and boost::simd::store functions to load data into the pack and store it back into memory.

@snippet arrayplus.cpp sum-include

The simplest approach, exclusive to arrays whose sizes are powers of 2, is to load the full array into a pack the size of the array.

@snippet arrayplus.cpp sum-packs

This section loads the full input array into a pack and fills another pack with our constant. This allows us to perform the substraction directly on the full array with one line of code.

For arrays whose sizes are not clean multiples of 2, we must use smaller sized packs (or pad the length to the next power of 2). It is generally simplest to use the default pack size, corresponding to the size of the available physical _SIMD_ registers. This size can be obtained using the boost::simd::cardinal\_of function.

Note that we increment our loop by the number of elements in our pack because we are treating more than one element per loop iteration.

The last two **Boost.SIMD** implementations must take advantage of this cardinal size in order to properly iterate over the array.
Both implementations must manually specify the memory address of the data to load into a pack, loading a few elements per loop iteration.
For each loop iteration, we must load the array data into a boost::simd::pack, perform the substraction between packs, then store the result into the output array.

There are two ways to load data into our packs:

1. By explicitly calling the boost::simd::load function
@snippet arrayplus.cpp sum-load

2. By constructing a boost::simd::pack with a pointer towards the correct address
@snippet arrayplus.cpp sum-pointer


Here is the full compilable code for reference.

@snippet arrayplus.cpp sum


@section tutorial-reduction Reductions

----------------------------------------------------------------------------------------------------
Now that we know how to handle simple _SIMD_ kernel, let's have a look at more complex operations involving operations across the values stored in a boost::simd::pack.

Here we will examine how to calculate the sum of the contents of an array. The scalar way to calculate this is as follows:

@snippet reduction.cpp reduc-scalar

We see here that there is a dependence between loop iterations - the accumulated sum. However, this dependency can be eliminated by forming our addition in the binary tree form shown here:

@snippet binary.txt binary

If we had an infinitely large _SIMD_ register, this would allow us to calculate the sum of _n_ elements in _log(n)_ steps. Unfortunately, we do not have infinitely large registers (even GPUs are limited in their number of simultaneous calculations), but we can combine the two approaches to nonetheless gain a certain amount of performance.

Here we combine the approaches by summing into a boost::simd::pack, allowing us to perform as many simultaneous additions as there are elements in a pack. It is only at the end that we accumulate these sub-sums into the full scalar sum using the boost::simd::sum function provided by boost/simd/function/sum.hpp.

@snippet reduction.cpp reduc-simd-o

If the size of our array is known at compile time and is a power of 2, we may let boost::simd::pack and boost::simd::sum handle the hard parts and simply write

@snippet reduction.cpp reduc-simd-l

Here is a full code, should you wish to compile it.

@snippet reduction.cpp reduc

#TODO: General reduction operations, transforms

#TODO: Aligned memory

@section tutorial-process Processing data the SIMD way

----------------------------------------------------------------------------------------------------
This tutorial will present how data can be processed using **Boost.SIMD** by writing a naive dot product using **Boost.SIMD**.

A simple sequential, scalar dot product can be simply defined as:

@snippet dot.cpp scalar-dot

dot simply iterates over data pointed by first1 and first2, computes the product of said data and sum them along.

@subsection tutorial-simd-way Transition from scalar to SIMD code

In this case the algorithm is clearly vectorizable, we shall modify it so that this becomes evident.

First, we unroll the loop arbitrarily showing the inherent data parallelism:

@snippet dotunroll.cpp scalar-dot-unroll

The algorithm is split into two parts:

First, we loop over each element inside both datasets and multiply them.
Then, we sum the intermediate values into the final result.
By unrolling this pattern arbitrarily, we expose the fact that the multiplication between the two dataset is purely "vertical" and so, is vectorizable. The sum of the partial results itself is a "horizontal" operation, i.e a vectorizable computation operating across the element of a single vector (see @intra-register operation).

@subsection simd_loop Building a SIMD loop
We are now going to use boost::simd::pack to vectorize this loop. The main idea is to compute partial sums inside an instance of boost::simd::pack and then perform a final summation. To do so, we will use boost::simd::load to load data from first1 and first2, process these boost::simd::pack instances using the proper operators and advance the pointers by the size of the boost::simd::pack.

@snippet dotsimd.cpp scalar-dot-simd
That's it! Look at how similar the computation code is to the scalar version, we simply jump over data using a larger step size.

# Note:

the code line `tmp = tmp + x1 * x2;` could have been replaced by
`tmp += x1 * x2;` or even `tmp = fma(x1, x2,tmp);` (after having included `boost/simd/function/fma.hpp`)
which will lead to same code if hardware does not support fma, or even better code if it does.


@subsection prepare-data Preparing the data
@section tutorial-shuffle Memory Access

----------------------------------------------------------------------------------------------------

## The result

@section tutorial-select Runtime Extensions Selection

----------------------------------------------------------------------------------------------------
Using **Boost.SIMD** requires compiling for a particular target machine with specific _SIMD_
instructions available. For many architectures (x86 in particular), _SIMD_ instructions may be conditionally supported depending on the exact hardware being used, with more recent hardware
typically supporting more _SIMD_ instructions than older ones.

In this tutorial, we will demonstrate how to switch between `SSE` and `AVX` for the same code
depending on the capabilities of the x86 hardware that the program is running on.

## The result
