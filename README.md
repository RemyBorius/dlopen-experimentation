# dlopen experimentation

This repository is a test on dlopen usage as I am personally running into some very special cases in C++ :

 * **How do I load a shared library with dlopen WITHOUT having to modify it ?**

> I use gcc 10 to compile

***

## Good resources

* **The linux manual :**  `man dlopen` in command shell
* **[C++ dlopen mini HOWTO](https://tldp.org/HOWTO/C++-dlopen/intro.html) :** A very well explained tutorial on how to use dlopen in C++

***

## My problem

### Description

I work on a project that use a shared library, which is proprietary. This implies I can't modify it (just remember it ll be the main problem).  
My job is to optimise my project by using multi threading. However, I observed that the library I'm using can only handle one thread at a time, and block all the others when processing one.  
So in the end, my optimisation is very poor. 

So I came out with a solution : **instead of loading only once the lib and getting blocked at each thread using it, I would rather load a version of my lib for each thread, so there is no more waiting !**

So I discovered the dlopen library, that can do exactly what I want ... but more easily in C than in C++ :/

### Step 1 : having a simple working example of loading a shared lib with dlopen 


Here's the first issue, and how I solved it :
* dlopen has been developed for loading libs in C. To do that, it needs to load separately each function from the loaded lib by using its mangled name.
* The mangled name of a function basically is its unique ID :
  * in C, it's just the name of the function (if the function is `myFunc(int x)`, the mangled name is `myFunc`)
  * in C++, it's some kind of weird string of char that also represent the values of the parameters of the function (if the function is `myFunc(int x)`, the mangled name could be `myFuncD45_H`)  
    > note that the mangled name in C++ depends on which compiler you use, it can be different of between compilers, and even compiler versions.  
      I use GCC 10 to compile
* So in C++, two things can be done to use dlopen :
  * Use the `extern "C"` keyword that forces the compiler to use the C mangling, but prevent from using overloading and methods
  * As my lib is proprietary, I can't modify it and upper method is not a possibility, I had to look for the mangled name manually by parsing the compiled `.so` file of the shared lib (I used the method described in this [stackoverflow thread](https://stackoverflow.com/questions/73419669/how-to-get-the-mangled-symbol-of-a-function-in-c))

This solution works well ! only problem : it does work only with 'normal' functions, and not with methods ... And I need to use a method

> `case_1` is my example, to test it :
>  
> * compile the `hello` lib
> * compile and run `case_1_dlopen` executable
> 
> The output should be working for the helloFunction, but it gives an error for the helloMethod

### Step 2 : having a working example of loading a class and its methods

The `case_2` folder is my attempt to import both the object and its methods, I inspired my attempt by [the part 3.3 Loading Classes](https://tldp.org/HOWTO/C++-dlopen/thesolution.html).  
The main idea is to use polymorphism as a workaround to use the imported object and its methods (check the link for more info)

Good news, it's working well too ! 

> `case_2` is my example, to test it :
>
> * compile the `hello2` lib
> * compile and run `case_2_dlopen` executable

### Step 3 : having the same result as step 2, BUT now it's forbidden to modify the Hello class so it's possible import it with dlopen

Now is the real challenge. I can't modify the Hello class. It's where I need some help.  
My idea was to create the `HelloTampon` class that inherit of both the `Hello` class and the `helloInterface` class, so I can use it as the `Hello` class and I can modify it at will as I create it myself.  

And it works now ! big joy rn

> `case_3` is my example, to test it :
>
> * compile the `hello3` lib
> * compile the `helloTampon` lib
> * compile and run `case_3_dlopen` executable

### Step 4 : dlmopen and some verifiactions

I used `dlmopen` to load separately two version of the same library
I added a global variable to see if the two versions are really independent. And they are !

## Conclusion

Total success !  
I want to thank people from the `Together C & C++` discord server for there help and there will to help ! (especially Dot)
