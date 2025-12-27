add_executable(01_InsertSort 01_InsertSort/main.c
		./sortHelper.c ./sortHelper.h
		01_InsertSort/insertSort.c
		01_InsertSort/insertSort.h)

add_executable(02_SwapSort 02_SwapSort/main.c
		./sortHelper.c ./sortHelper.h
		02_SwapSort/bubbleSort.c
		02_SwapSort/bubbleSort.h
		02_SwapSort/quickSort.c
		02_SwapSort/quickSort.h
)