/*
	Title:			stack.c
	Description:	Stack ADT
	Author:			Shalev Goldfarb
	Last updated:	07.04.19
*/

stack_t* StackCreate(size_t _size, size_t _blockSize)
{
	stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
	if (NULL == stack)
	{
		return stack;
	}

	stack->m_vector = VectorCreate(_size, _blockSize);
	if (NULL == stack->m_vector)
	{
		free(stack);
		return NULL;
	}

	stack->m_vector->m_magicNumber = 0xbeefbeef;
	stack->m_vector->m_originalSize = _size;
	stack->m_vector->m_size = _size;
	stack->m_vector->m_nItems = 0;
	stack->m_vector->m_blockSize = _blockSize;

	return stack;
}

void StackDestroy(stack_t* _stack)
{
	if ((NULL == _stack) || (0xbeefbeef != _stack->m_vector->m_magicNumber))
	{
		return;
	}
	_stack->m_vector->m_magicNumber = 0xdeadbeef;
	VectorDestroy(_stack->m_vector);
	free(_stack);
}