typedef struct {
    void (*init)(void);
    void (*deinit)(void);
    void (*cyclic100ms)(void);
} task_t;
