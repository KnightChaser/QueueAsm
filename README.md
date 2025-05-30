## `QueueASM` 📦

> A dynamic integer(`int64_t`) queue implemented in **Assembly** (x86\_64 NASM, System V AMD64 ABI) with a C-based interactive CLI wrapper. Maybe perfect for learning linked lists in Assembly—zero BS.

### Preview
![image](https://github.com/user-attachments/assets/c8632b60-b473-4fd4-9a3b-66d5962b3efd)


### File Structure


* **Assembly core** in `src/` handles all queue operations (create, enqueue, dequeue, peek, count, empty check, print, destroy).
* **C CLI** in `main.c` offers an interactive shell for exercising the queue: `enqueue`, `dequeue`, `peek`, `print`, `count`, `empty`, `help`, `exit`.

```
.
├── Makefile              # build rules using NASM and GCC
├── main.c                # interactive command-line interface in C
├── README.md             # this documentation >_<
└── src
    ├── structs.inc       # Node and Queue struct layouts & constants
    ├── create_queue.asm  # queue_create
    ├── enqueue.asm       # queue_enqueue
    ├── dequeue.asm       # queue_dequeue
    ├── queue_utils.asm   # queue_count, queue_is_empty, queue_peek, queue_print, queue_destroy (utilities)
```

### Build & Run

```bash
make clean && make    # assemble, compile, and link into ./queue
./queue              # launch the interactive CLI
```

### CLI Commands

* `enqueue <n>` : add integer `n` to the queue
* `dequeue`     : remove & print the front element (underflow exits with error)
* `peek`        : print the front element without removing
* `print`       : dump all elements in FIFO order (`val1 -> val2 -> ...`)
* `count`       : display the number of elements
* `empty`       : prints `1` if empty, `0` otherwise
* `help`        : show this help message
* `exit`        : quit the program (frees all memory)

### License & Contributions

This project is open source under the MIT License. Contributions, issues, and patches are welcome — let's keep it lean and mean! >_<
