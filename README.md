# Pointers and the Address Of Operator

## Map of a Process' Memory

* A process is a running program;
  * Many processes can run the same program code

* Each process' memory is isolated from others
  * This isolation is provided and enforce by the operating system and hardware. Trying to read or write to **segments of memory** you aren't allowed leads to a **segmentation fault (program crash).**
  * The operating system gives each process the illusion of having a vast, contiguos memory address space through **virtual memory**

* A key characteristic of a systems language is it gives you more direct access to memory-level concerns and capabilities.

---

## The Call Stack

* Variables local to function calls are typically found in the "Stack" or a function call stack

* Each function call has a frame on the stack
  * This enables separation of storage between functions. Useful for separating concerns between and limiting knowledge between functions. Critical for generalized recursion.

* Frames not only contains variable's values, but also:
  * Argument values
  * Return address
    * Where in the program to resume execution once the function returns
  * Return value
    * Space where return value is shared between caller and callee
  * Additional CPU State

---

## & The Address of Values in Memory

* See example1.c

* The C programming language has an "address of" operator which evaluates to the address of its operand in memory.
  * A memory address depends on the word size of a computer. On a 64-bit laptop the word size is 64 bits. Think of it as a (vaery large!) unsigned integer.

* To print a memory address with **printf**, use the **%p** format specifier
  * The p stands for **pointer**, which is a name for a memory address

* Consider the output:
  * Notice how enourmous the hex values are! As an unsigned integer **&b** is 140,738,771,505,832

  * Also notice since a **char** is a single byte, the addresses of a and b are right beside each other.

* Takeaway: The **stack** is in high memory addresses. Local variables are collocated within their stack

---

** Visualization of Type Widths

* see example2.c

* Notice that the type of a variable establishes the bit-width in memory

* Variables whose types are larger than 1-byte span multiple addresses in memory!
  * We will asume "little endian" meaning when a value spans multiple addresses, its low-order bits will be in the low-address end of the range.

* Reminder: variable names are for humans only! The compiler does the bookkeeping to produce machine programs that operate in terms of memory addresses with no memory representation of variable names

---

** Aside: Why do addresses change each time a program runs?

* Running any of the previous programs results in different output every single execution. Why?

* The operating system intentionally randomizes the starting address of the call stack every time a program runs
  * ASLR (Address Space Layout Randomization)

* Why? Hacking programs becomes more difficult when the exact address of data have some randomness.

* Notice it's not all random, though. The high-order bits keeps the stack starting in the same general vicinity of addresses.

---

** Pointers are Addresses to Memory

* In systems programming languages pointers are a first-class data type
  * Can be stored in variables, passed as parameters, return from function
  * You can dereference a pointer to read that memory address's contents

* What is the point of pointers? Why haven't you needed them before?
  * It turns out you have needed them before
    * Java Reference types (arrays, objects) are opaque pointers to heap values.
    * In "memory managed" languages you have limited control of and visibility into pointers, but they're very much there!
  * Big Idea: Pointers enable sharing data structures between function calls without having to copy the structure
  * Other use cases: Many!
    * Efficient iteration through arrays.
    * Sorting strings and objects without having to move their values around in memory.
    * Dynamic dispatch of functions

---

** Visualizing a Pointer in Memory

* See pointer_demo.c

* Since 64-bit memory addresses are themselves 64-bits wide, to store an address in a pointer requires 8 bytes as shown for a_char_ptr

* BIG IDEA: the address of a_char is what is sotre in the contents of a_char_ptr!

---

** Pointer Parameters

* See pointer_demo2.c

* Parameters can be pointers
  * In doing so, it gives functions the ability to read from and to memory addresses they otherwise would not have access to.

* Previous ex modified **main's local** variable... **from outside its scope!**

* You have kind of seen this before in Java / Python / Typescript when you have parameters of type array or object (reference types)
  * In those cases what you're actually passing are pointers to the same array / object.
  * However, in the languages it is impossible to pass pointers to primitive local. No such restrictions exist in systems languages like C because you are working more transparently at the memory address level.

* See pointer_demo_invalid.c for an example of a function that returns a addres of local variable

* We will see this is commonly done when writing "object-oriented style" C

---

** Addresses are just numbers (with Context)

* You can perform (limited) arithmetic on pointers and addresses
  * You can add and subtract integers from poitners
  * You can subtract two pointers of the same type

* Most useful when working with pointers to array elements
  * Sometimes for hackier reasons

* The actual byte arithmetic is contextual to the pointer's type
  * If you were adding one to the address to a uint32_t variable, such as &a_uint32 + 1, the result would increase the address by 4 bytes!
  * Implicitly, the number being added or subtracted from the pointer is being scaled by the type's byte width.

---

** Array Indexing vs. Pointer Arithmetic

* An array variable in C is a special pointer to address of first element
  * Different than a plain pointer because it cannot be reassigned
  * Also different because sizeof(array) reports size in bytes of complete array

* Array indexing notation is just syntatic sugar for pointer arithmetic:
  * a[i] is the same as *(a + i)
  * a[0] is the same as *(a + 0) and the same as \*a

* Since an array's name is just a pointer to its first element, you can assign it directly to a pointer of the same element type:

```c
    int numbers[] = { 10, 20, 30 };
    int *p = numbers;
    printf("%d", *p); // prints 10
```
