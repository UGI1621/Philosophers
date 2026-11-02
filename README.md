*This project has been created as part of the 42 curriculum by saan.*

# Description

This project is a simulation of the Dining Philosophers problem using threads and mutexes.
Each philosopher is a thread, and each fork is shared between two neighboring philosophers and protected by a mutex.

## 1. Project Goal

Understand the basics of multithreading: creating threads, protecting shared data with mutexes, and avoiding deadlocks and data races.

## 2. Process

When the program is executed, it takes 4 or 5 numeric arguments.
It validates the arguments, then initializes the forks and the philosophers.

The philosophers are stored in a circular doubly linked list, and each philosopher points to its left and right fork.

All philosopher threads and one monitor thread are created, and they wait until every thread is ready so the simulation starts at the same time.

Each philosopher repeats the following cycle:

1. Take two forks
2. Eat
3. Put down the forks and sleep
4. Think

To prevent deadlock, odd-numbered philosophers take the left fork first, and even-numbered philosophers take the right fork first after a short delay.

Each philosopher tracks its remaining time to die. When it runs out, the philosopher prints its death and the simulation stops.

The monitor thread checks whether a philosopher has died or whether every philosopher has eaten the required number of times, and ends the simulation in either case.

All output is protected by a print mutex, and no message is printed after a philosopher dies.

## 3. Notes

The simulation ends when a philosopher dies.
If `number_of_times_each_philosopher_must_eat` is given, it also ends when every philosopher has eaten at least that many times.

If there is only one philosopher, they can take only one fork, so they will die.

# Instructions

Open a terminal in the `philo` folder of this project.

```bash
make
```
Use the command above to compile the program.

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
Use the command above to run the program.
All times are in milliseconds.

Example
---

```bash
./philo 5 800 200 200
./philo 5 800 200 200 7
./philo 4 410 200 200
./philo 1 800 200 200
```

Output format
---

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

```bash
make clean
```
This command removes the object files.

```bash
make fclean
```
This command removes both the object files and the program executable.

# Resource

[Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)<br>
[pthread_create](https://man7.org/linux/man-pages/man3/pthread_create.3.html)<br>
[pthread_mutex_lock](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)<br>
[gettimeofday](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)<br>
<br><br>

# AI Usage

AI was used for:

__Writing this README__<br>
