<h1 align="center">
  🍽️ 42 Philosophers</h1>
</h1>

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/philosopherse.png" alt="philos_badge"/>
</p>

<h2 align="center">
  🎓 Significance
</h2>
<p align="center">
  <p>The Dining Philosophers problem is a fundamental example in both computer science and philosophy. It illustrates the challenges of resource allocation and process synchronization in concurrent programming. By simulating philosophers who must share limited resources (chopstick) without causing deadlock or starvation, this problem teaches important concepts that are applicable to real-world systems where resources are limited and processes must be managed efficiently.</p>

<p align="center">
  <img src="philos.png" alt="Dining Philosophers"/>
</p>

***

<h2 align="center">
  Overview
</h2>
<p align="center">
  <p>This project is a simulation of the classic Dining Philosophers problem, where philosophers alternate between eating, thinking, and sleeping while trying to avoid starvation and deadlocks. The goal is to understand and implement concepts of multithreading and synchronization using mutexes.</p>


## 💡 Concepts

- **Multithreading**: Using POSIX threads (`pthread`) to create concurrent execution flows.
- **Mutexes**: Synchronization primitives to avoid race conditions when accessing shared resources.
- **Deadlock Prevention**: Ensuring that philosophers do not block each other indefinitely.
- **Dynamic Memory Management**: Using `malloc` and `free` to manage memory allocation.

## 📋 Table of Contents

- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [Concepts](#concepts)
- [Code Structure](#code-structure)
- [Significance](#significance)

## ⚙️ Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/pandashaly/philos.git
   cd philos
2. Compile the project using the provided Makefile:

    ```bash
    make
    ```

## 🚀 Usage

Run the program with the following command:

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: The number of philosophers and chopstick.
- `time_to_die`: Time in milliseconds before a philosopher dies without eating.
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: Time in milliseconds a philosopher will spend sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation stops when each philosopher has eaten at least this many times.

### Example

```bash
./philo 5 800 200 200
```

This will run the simulation with 5 philosophers, where each philosopher has 800 milliseconds to live without eating, 200 milliseconds to eat, and 200 milliseconds to sleep.

---

## 📁 Code Structure

```rust
42-philosophers/
├── Makefile
├── main.c
├── philos.h
└── README.md
```

- `Makefile`: Contains rules to compile the project.
- `main.c`: Contains the main program and function implementations.
- `philosophers.h`: Header file with struct definitions and function prototypes.
- `README.md`: This readme file.

### 📚 What I Learned

By doing this project as part of my 42 Core Curriculum, I learned the importance of multithreading and synchronization in software development. I gained practical experience with POSIX threads (`pthread`) and mutexes, which are essential for managing concurrency and ensuring that shared resources are used safely. Additionally, I understood the complexities of avoiding deadlock and starvation, which are critical for creating robust and reliable systems.

***

## Ressources

* [Parallel Computing](https://computing.llnl.gov/tutorials/parallel_comp/)
* [POSIX Threads](https://computing.llnl.gov/tutorials/pthreads/) ([pthread routines](https://computing.llnl.gov/tutorials/pthreads/#AppendixA))
* [Working example](https://timmurphy.org/2010/05/04/pthreads-in-c-a-minimal-working-example/)
* [Semaphores in C](http://greenteapress.com/thinkos/html/thinkos012.html)
* [fork() example](https://timmurphy.org/2014/04/26/using-fork-in-cc-a-minimum-working-example/)
* [fork() multiple childs](https://stackoverflow.com/questions/876605/multiple-child-process)
* [Semaphore when programs end](https://stackoverflow.com/questions/9537068/sem-close-vs-sem-unlink-when-process-terminates)

