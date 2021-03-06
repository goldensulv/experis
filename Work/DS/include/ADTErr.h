#ifndef __ADTERR_H__
#define __ADTERR_H__

typedef enum 
{
	OK = 0,
	GENERAL_ERROR,
	PARAMETER_ERROR,
	POINTER_ERROR,
	INITIALIZATION_ERROR,
	ALLOCATION_ERROR,
	REALLOCATION_ERROR,
	UNDERFLOW_ERROR,
	OVERFLOW_ERROR,
	INDEX_ERROR
} ADTErr;

#endif /* __ADTERR_H__ */