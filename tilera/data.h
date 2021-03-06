#ifndef DATA_H
#define DATA_H
#include <ilib.h>

typedef ilibMutex ilib_mutex_t;

typedef struct data_t {
	int tid;
	int lim;

	// the dimensions of the n x n array
	int dim;

	int thread_rows;
	int thread_offset;

	// error counters
	double thread_error;
	ilib_mutex_t *error_lock;
	double *global_error;

	// in a Jacobi transformation, we can assume that the matrix
	//	is an n x n square, invertible matrix
	double **thread_a;
	double *thread_b;
	double *thread_x;

	// x_temporary array to do initial calculations in
	double *thread_xt;
} data;

data * data_init();
void data_dim(data *, int, int);
void data_allocate(data *, int);
void data_vomit(data *);

#endif
