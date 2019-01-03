# Register
CPU 내부에 존재하는 고속의 저장 공간. IA-32란 Intel Architecture 32bit를 의미함.

IA-32에는 Basic program excution, MMX, XXM, Contorl, Memory, Debug 등 다양한 레지스터가 존재한다.

4장에서는 Basic program excution register에 대해서만 다룬다. 추후에 Memory, Debug, Control 레지스터에 대해 다룬다.

## Basic Programming Reigster
- General Purpose Registers
- Segment Registers
- Program Status and Control Registers
- Instruction Pointer

Basic Programming Register는 4개의 그룹으로 나뉜다.

## General-Purpose Registers
- EAX : Accumulator for operands and results data, Win32 API 함수들의 리턴 값을 저장
- EBX : Pointer to Data in the DS segment
- ECX : Counter for string and loop operations, Loop문에서 Counter로 사용
- EDX : I/O Pointer
- ESI : Pointer to data on the stack (in the Stack Segment)
- EDI : Source pointer for string operations
- EBP : Destination pointer for string operations
- ESP : Stack Pointer (in the Stack Segment)

범용적으로 사용되는 레지스터. 각 이름의 E는 IA-16부터 사용되던 레지스터를 Extended 하였다는 의미다.

EAX ~ EDX 레지스터들의 하위 16비트를 AX, BX 와 같이 E를 떼고 칭하고 AX, BX에서 상위 8비트를 AH, 하위 8비트를 AL 이런식으로 사용한다. 자료형에 맞춰서 알뜰히 사용할 수 있다.

EAX ~ EDX 레지스터는 산술연산 명령어에서 자주 쓰임. 목적(?)이 정해진 레지스터 같지만 대게 막 쓰고 EAX, ECX 이런 레지스터는 리턴 값 저장, 루프 카운터와 같이 특수 목적으로도 사용된다.

ESP, EBP는 스택에서 사용되는 레지스터로 스택 프레임에 아주 중요한 레지스터라 대개 다른용도로 사용하지 않는다.

ESI, EDI는 특수 목적 명령어 (LODS, STOS, REP MOVS...)와 결합하여 사용된다.

예를 들면 어떠한 명령어는 ESI가 가리키는 곳에서 데이터 읽어서 EDI가 가리키는 곳에 복사한다. 복사한 뒤 Direction Flag에 따라 가리키는 주소가 자동으로 1 또는 2씩 증감한다. (명령어에 따라 다르다)

## Segment Register
- CS : Code Segment
- SS : Stack Segment
- DS : Data Segment
- ES : Extra(Data) Segment
- FS : Data Segment
- GS : Data Segment

IA-32 보호모드는 메모리를 조각내어 각 조각마다 시작 주소, 크기, 접근 권한등을 부여하여 메모리를 보호한다. 이 때 각 조각난 메모리를 Segment라고 하며 Code, Stack Segment 등이 존재하며 이를 줄려서 CS(Code Segment), SS(Stack Segment)와 같이 사용한다.

각 Segment에 대한 정보는 Segment Descriptor가 가지고 있다.

Segment Register는 Segment Descriptor의 index를 가지고 있는 레지스터이다.

## EFlag Register
- EFLAGS : Flag Register

말 그대로 어떠한 상태 비트들이 모인 레지스터이다. Zero Flag, Overflow Flag, Carry Flag 등 Status Flag 뿐 아니라 Control Flag, System Flag도 포함하고 있다.

## EIP Register
- EIP : Instruction Pointer

다음 실행될 명령어의 주소를 가리키고 있는 레지스터. 명령어 실행 시 자동으로 다음 명령어를 가리키며 값을 직접 변경시킬 수 없도록 되어있다. 값을 변경하고 싶다면 JMP, CALL, RET등 다른 명령어 호출을 통해 간접적으로 변경하거나 Interrupt, Exception을 발생시켜 변경시켜야 한다.