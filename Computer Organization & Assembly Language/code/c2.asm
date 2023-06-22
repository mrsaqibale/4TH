global _start

_start:


		mov ah,01h
		int 0x80

		mov dl , al
		mov ah, 02h
		int 21h

