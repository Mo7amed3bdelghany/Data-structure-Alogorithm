# Introduction to Recursion


<details> <summary><h3> What is recursion
</h3></summary>

**Recursion** is a programming technique in which a function calls itself directly or indirectly.  It is used in a lot of important algorithms like DFS, Dynamic Programming (DP) and Backtracking.   

  - Directly call
    ```c++
    void fun(){
        fun();
    }
    ```
  - Indirectly call
    ```c++
    void fun1(){
        fun2();
    }
    void fun2(){
        fun1();
    }
    ```

Examples of Recursive algorithms: Merge Sort, Quick Sort, Tower of Hanoi, Fibonacci Series, Factorial Problem, etc.

</details>


 <details><summary><h3>Stopping Condition
</h3></summary>

We set a condition upon which the function stops calling itself and returns. This case is called the **Base Case**
```c++
void fun(int n){
    if(n==1) {return;} //  Base Case
    fun(n-1); // Statment makes tree
}
```

Key points to keep in mind:
- Ensure that the base case is well-defined to prevent infinite recursion (Stack Overflow error).
- Each recursive step should bring the problem closer to the base case.
</details>

    
<details><summary><h3>Recursive examples</h3></summary>
   <details><summary><h4>💡 Fibonacci example:</h4></summary>
0,1,1,2,3,5,8,........

```c++
#include <iostream>
int fib(int n){
    if(n==0 || n==1) return n; // Base case
    return fib(n-1)+fib(n-2); // Statment
}
int main(){
    std::cout<<fib(5);
}
```
[Watch this video](https://github.com/user-attachments/assets/15ab8fcc-e4d7-4a8f-ad67-df27e32f09d8)
</details>

<details><summary><h4>String of length K example:</h4></summary>
print all possible strings of length K that can be formed from a set n characters.

Input: `set` ={'a', 'b'}, k=3
Output:   
aaa    
aab   
aba    
abb  
baa    
bab    
bba    
bbb    
```c++
#include <iostream>
void fn(vector<char>s,string current, int k){
    if(current.size()==k){ // Base case
        cout<<current<<'\n';
        return;
    }
    for(auto it:s){
        fn(s,current+it,k); // Statmen
    }
}
int main(){
    vector<char> s={'a','b'};
    fn(s,"",3);
}

```
![](https://github.com/user-attachments/assets/7826c2e3-bdc7-499d-9087-0c29913b7995)

</details>
</details>


<details><summary><h3>How are recursive functions stored in memory?</h3></summary>

Recursion uses more memory, because the recursive function adds to the stack with each recursive call.

 A call stack is a memory stack where functions are pushed when they are called. It is used to keep track of currently running function, their priority and the order they were called in.
</details>

<details><summary><h3>How memory is allocated to different function calls in recursion? </h3></summary>

When any function is called from main(), the memory is allocated to it on the stack. A recursive function calls itself, the memory for a called function is allocated on top of memory allocated to the calling function and a different copy of local variables is created for each function call. When the base case is reached, the function returns its value to the function by whom it is called and memory is de-allocated and the process continues.

This is what happens inside the stack, Let's assume that we have a fibonacci function for the number 4 :-
 <img  src="https://github.com/user-attachments/assets/b2d31c72-82f3-46eb-86c8-5ae1f22a7bcb" alt="fibonacci_normal_call_stack" width="500"/>
</details>


<details><summary><h3>Time Complexity</h3></summary>
The Time Complexity of a recursive function is determined by how many times it's called.

For example the above code is called as many times as the value passed in the parameter. Thus it's time-complexity is O(n).   

</details>

<details><summary><h3>When should you think about using recursion?</h3></summary>

Whenever you encounter a problem that can be broken into smaller problems of similar type, you should consider using Recursion.

</details>



         
<details><summary><h3>Recursive programming <b><i>VS</i></b> Iterative programming
</h3></summary>
<h4><b>What are the disadvantages of recursive programming over iterative programming?</b></h4>
Note that both recursive and iterative programs have the same problem-solving powers, i.e., every recursive program can be written iteratively and vice versa is also true. The recursive program has greater space requirements than the iterative program as all functions will remain in the stack until the base case is reached. It also has greater time requirements because of function calls and returns overhead.

Moreover, due to the smaller length of code, the codes are difficult to understand and hence extra care has to be practiced while writing the code. The computer may run out of memory if the recursive calls are not properly checked.

<h4><b>What are the advantages of recursive programming over iterative programming?</b></h4>
Recursion provides a clean and simple way to write code. Some problems are inherently recursive like tree traversals, Tower of Hanoi, etc. For such problems, it is preferred to write recursive code. We can write such codes also iteratively with the help of a stack data structure. For example refer Inorder Tree Traversal without Recursion, Iterative Tower of Hanoi.

</details>


<details><summary><h3>Tail Call Optimization</h3></summary>

#### What is the tail recursion
- **Tail recursion** is defined as a recursive function in which the recursive call is the last statement that is executed by the function. So basically nothing is left to execute after the recursion call.
- The tail recursive functions are considered better than non-tail recursive functions as tail-recursion can be optimized by the compiler. 
- Is the process by which a smart compiler can make a call to a function and take no additional stack space.   
- Tail calls be implemented without adding a new *stack frame* to the *call stack*. Most of the frame of the current procedure is no longer needed, and can be replaced by the frame of the tail call, modified as appropriate (similar to *overlay* for processes, but for function calls). the program can then *jump* to the called subroutine. producing such code instead of a standard call sequence is called tail call elimination or tail call optimizaion.

#### Advantages:
1. Just discard unnecessary function from the stack.
2. Same results.
3. O(1) space instead of O(n) space.
4. Faster Too!


### Tail Recursive Function:

Is this tail recursive function ??
```c++
int fac(int n){
    if(n < 2) return 1;
    return n * fac(n - 1);
}
int main(){
    int n = 5;
    std::cout<<fac(5);
}
```
Actulally no becuse the last operation is the multiplication and not the function call.

However, it's possible to rewrite fac() to be tail-recusive by passing the accumulated / value down the call chain as an additional argument and passing only the final result up again return value:
```c++
int fac_tailrec(int acc, int n){
    if(n < 2) return acc;
    return fac_tailrec(acc * n, n - 1);
}
int main(){
    int n = 5;
    std::cout<<fac_tailrec(1, n)
}
```
Now, ***Why is this useful?***
- Because we immediately return after the tail call, we can discard the previous stack frame before invoking the function in tail position or in case of recursive functions, reuse the stack frame as-is.

The tail-call optimization transforms our recursive code into:
```c++
int fac_tailrec(int acc, int n){
Top:
    if(n < 2) return acc;
    acc*= n;
    n--;
    goto Top;
}
```

As we can see here a sufficient advanced optimizer can replace tail-recursion with iterative, which is far more efficient as you avoid function call overhead and only a constant amount of stack space.

#### Can we do this for all recursive algorithms?
- No! Results returned by always_zero(0) need to be further processed by always_zero(1)
- Results form always_zero(0) cannot be returned dirctly to main().
- Need to pass through always_zero(1), always_zero(2), always_zero(3), ...
```c++
  int always_zero(int i){
    if(i==0) return 0;
    return 5*always_zero(i-1);
  }
  
  int main(){
    always_zero(5);
  }
``` 

</details>


















