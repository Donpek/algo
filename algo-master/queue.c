typedef struct
{
    i32 CurrentSize;
    i32 HeadIndex;
    i32 MaxSize;
    i64 *Memory;
} array_queue_t;

internal void
QueueInitialize(array_queue_t *Queue, void *Memory, u32 MaxSize)
{
	Queue->Memory = (i64 *)Memory;
	Queue->MaxSize = MaxSize;
	Queue->CurrentSize = 0;
	Queue->HeadIndex = 0;
}

internal void
QueueEnqueue(array_queue_t *Queue, i64 NewElement)
{
	i32 CurrentSize = Queue->CurrentSize;
	if(CurrentSize < Queue->MaxSize)
	{
		i32 NewIndex = (Queue->HeadIndex + CurrentSize) % Queue->MaxSize;
		Queue->Memory[NewIndex] = NewElement;
	}
	++Queue->CurrentSize;
}

internal i64
QueueDequeue(array_queue_t *Queue)
{
	i32 HeadIndex = Queue->HeadIndex;
	i64 Result = Queue->Memory[HeadIndex];
	if(HeadIndex == Queue->MaxSize - 1)
	{
		Queue->HeadIndex = 0;
	}else
	{
		++Queue->HeadIndex;
	}
	--Queue->CurrentSize;
	return(Result);
}
