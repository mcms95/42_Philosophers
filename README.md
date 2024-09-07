# 42_Philosophers

## Theory

- Every process is made of threads
- Compiling with -lpthread  flag -> gcc your_source_file.c -o output_file -lpthread  
- When working with threads in programming, each thread gets a unique identification. This identification is crucial when it comes to managing threads.
    - pthread_t represents the ID of a thread in UNIX-like systems.

## Threads

- std lib is #include <pthread.h>

## Common functions

- pthread_create() -> Create a new thread
- pthread_exit() -> Terminate a thread
- pthread_join() -> Wait for a specific thread to finish
- pthread_mutex_lock & - pthread_mutex_unlock() -> Lock and unlock a mutex
- pthread_cond_wait() & - pthread_cond_signal -> Wait and signal on condition variables 
-phtread_mutex_destroy(&data->mutex) -> Destroy de mutex

## Race conditions

- Race condition is a situation in which the behaviour of a sotfware system depends on the relative timing of events, sush as the order in which the threads are scheduled on.

## Mutex 

- Mutex allows us to encapsulate a piece of code, so we can access a resorce via thread one at a time

## Thread vs proccess

- Proccess is the ful store
- Threads are the workers of the store

- Proccess are diferent entities from each other
- Threads share the same memory, the same store, they dont share information across proccesses

- So race conditions are intra-procces not inter-proccess

## Time

- We can get time in seconds or microseconds

we use the struct timeval and function gettimeofday to get the time that are in <sys/time.h> library

## Singleton

- A singleton in C is a design pattern that ensures only one instance of a class can be created and provides a global point of access to that instance.
- In this case we call data() and it returns a pointer to our main struct of type t_data
- Access a paramater - data()-> time_to_die;
- Can be initialized in any part of the program to be accessible 

```c
#include <sys/time.h>

struct timeval {
    time_t      tv_sec;     /* seconds */
    suseconds_t tv_usec;    /* microseconds */
};

int main() {
    struct timeval tv;
    int result;

    // Get the current time
    result = gettimeofday(&tv, NULL);

    if (result == 0) {
        printf("gettimeofday() succeeded. Return value: %d\n", result);
        printf("Seconds since epoch: %ld\n", tv.tv_sec);
        printf("Microseconds: %ld\n", tv.tv_usec);
    } else {
        printf("gettimeofday() failed. Return value: %d\n", result);
    }

    return 0;
}
```

#### Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./philo 800 700 700 700


## Study material:

### Medium
- https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2

- https://medium.com/@jalal92/the-dining-philosophers-7157cc05315


### Youtube: 

- Neso academy intro to threads -> https://www.youtube.com/watch?v=LOfGJcVnvAk


- Portfolio courses intro to threads -> https://www.youtube.com/watch?v=ldJ8WGZVXZk

- CodeVault threads playlist -> https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

- General project overview -> https://www.youtube.com/watch?v=UGQsvVKwe90&t=2005s

- Oceano -> https://www.youtube.com/watch?v=zOpzGHwJ3MU&t=1s
