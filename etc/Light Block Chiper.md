# Light Block Chiper

IoT 맬웨어 코드가 늘어나는중.

인증이 IoT기기를 맬웨어로부터 보호하는 기본적인 기능

SIMD

Chaskey
-MAC 알고리즘. 마이크로컨트롤러를 위한
암/복호화에 필요한 사이클 줄였음. 아주 빠른 실행속도. ARX의 조합 Add Rotation Xor

LEA경량암호
-역시 경량함호

ARM프로세서에 적용
SIMD based 인증 프로토콜.
암/복호 : Lea-128 CTR모드 사용
CTR은 암/복호화가 동일한 알고리즘이라 콛 ㅡ사이즈 감소 가능.
MAC : Chaskey이용
재전송공격, 메세지 변조 공격 방어
