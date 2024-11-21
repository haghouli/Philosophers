# Philosophers - 1337 Project

## Description
The **Philosophers** project at 1337 simulates a dining philosophers problem using multithreading and synchronization techniques. The goal is to write a program that simulates a number of philosophers sitting at a round table, each thinking and eating noodles. The challenge is to manage synchronization between the philosophers to prevent deadlock, starvation, and ensure that the simulation runs efficiently.

### Problem:
There are `N` philosophers sitting around a table. Each philosopher thinks and occasionally needs to eat. To eat, a philosopher requires two forks, which are placed between each pair of philosophers. However, only one philosopher can use a fork at a time, and they must not deadlock while trying to access the forks.

### Requirements:
- The program should handle multiple philosophers (at least 2, typically 5 for the example).
- The program should ensure no deadlock or starvation occurs.
- Each philosopher should have an equal opportunity to think, eat, and stop the simulation.
- The program must handle synchronization using mutexes to protect shared resources (the forks).
  
## Features
- **Multithreading**: Each philosopher runs on a separate thread.
- **Synchronization**: Mutexes are used to avoid conflicts when philosophers pick up and put down forks.
- **Deadlock Prevention**: The program should avoid situations where philosophers are stuck waiting for each other indefinitely.
- **Starvation Prevention**: Ensure that no philosopher is left eating while others are indefinitely starving.
- **Input Parameters**: The number of philosophers, time to eat, time to think, and maximum number of times a philosopher can eat can be set via program arguments.

## Installation

### Clone the Repository:
```bash
git [clone https://github.com/yourusername/philosophers.git](https://github.com/haghouli/Philosophers.git)
cd philosophers
make
