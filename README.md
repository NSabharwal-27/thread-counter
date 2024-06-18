# Thread Counter Project

This project demonstrates the use of POSIX threads (pthreads) to increment a global counter using multiple threads in a synchronized manner. The main focus is on thread creation, synchronization using mutexes, and proper handling of resources.

## Project Structure

```
thread-counter/
├── include/
├── src/
│   └── main.c
├── Makefile
└── README.md
```

### Files and Directories

- `include/`: Directory reserved for header files (currently empty).
- `src/`: Contains the source code for the project.
  - `main.c`: The main source file containing the implementation of thread creation and synchronization.
- `Makefile`: The makefile used to build and clean the project.
- `README.md`: This README file providing an overview of the project.

## main.c

The `main.c` file contains the implementation of a multi-threaded program that creates 18 threads, each of which increments a global counter (`GLOBAL_COUNTER`) in a thread-safe manner.

### Key Components

- **Global Counter**: 
  - `int GLOBAL_COUNTER = 0;`
  - A global variable incremented by each thread.
  
- **Mutex**: 
  - `pthread_mutex_t lock;`
  - A mutex to ensure that only one thread can increment the global counter at a time, preventing race conditions.

- **Thread Function**: 
  - `void *incrementCount(void *vargp);`
  - The function executed by each thread. It increments the global counter while holding the mutex to ensure thread safety.

- **Main Function**:
  - Initializes the mutex.
  - Creates 18 threads, each running the `incrementCount` function.
  - Waits for all threads to finish using `pthread_join`.
  - Destroys the mutex before exiting.

### Example Output

```
tid:0 has incremented GLOBAL_COUNTER to: 1
tid:1 has incremented GLOBAL_COUNTER to: 2
...
tid:17 has incremented GLOBAL_COUNTER to: 18
```

## Build and Run

### Prerequisites

- GCC compiler
- Make utility

### Steps to Build and Run

1. **Compile the Program**:
   ```
   make
   ```

2. **Run the Executable**:
   ```
   ./count
   ```

3. **Clean the Build**:
   ```
   make clean
   ```

## Important Aspects

- **Thread Creation**: 
  - The program creates 18 threads using `pthread_create`.

- **Thread Synchronization**: 
  - Mutexes (`pthread_mutex_t lock`) are used to ensure that only one thread can access and modify the global counter at a time.

- **Memory Management**: 
  - Each thread receives a dynamically allocated integer for its ID, which is freed within the thread function to prevent memory leaks.

- **Thread Joining**: 
  - The main function waits for all threads to complete using `pthread_join` to ensure that the main program does not exit before the threads finish their execution.