## Pattern(s)

### Errors
the main error handler is a function named *erro_exit*
```c
int	error_exit(const char *msg, int code)
```

the pattern macros to the msg is define as 

```c
#define ERR_AMOUNT_ARGS "[Error]: Invalid number of arguments"
```

### typedef && struct

the tmp name after the key_word tydef always must be s_@name, and the 
definition must start with t_@name

s_ -> struct
t_ -> typedef

```c
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
} t_mlx;
```