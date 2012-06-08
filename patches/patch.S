		.globl _start
_start:

.set DLLLoaderHook, 0x82332630
.set LoadLibraryA, 0x82332A98
.set DLLLoaderString, 0x82000868
.long DLLLoaderString
.long (9f-0f)/4
0:
	.string "game:\\dll_load.dll"
	.align 1
9:

.long DLLLoaderHook
.long (9f-0f)/4
0:
	lis %r11, DLLLoaderString@h
	ori %r3, %r11, DLLLoaderString@l
	bl (LoadLibraryA - (DLLLoaderHook + 0x8))
9:
.long 0xFFFFFFFF

