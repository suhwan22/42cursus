# push_swap
42seoul에서 진행하는 push_swap프로젝트는 제한된 명령어를 사용하여 스택을 정렬하는 알고리즘 과제입니다.<br/>
목표는 주어진 중복이 없는 정수 배열을 두 개의 스택(`stack a`와 `stack b`)을 이용하여 최소한의 명령어로 정렬하는 것입니다.<br/>
이를 통해 자료구조와 알고리즘의 활용 능력을 기를 수 있습니다.

## 목차
1. [프로젝트 목표](#프로젝트-목표)
2. [사용 가능 명령어](#사용-가능-명령어)
3. [학습 목표](학습-목표)
4. [파일 구조](파알-구조)
5. [사용 방법](사용-방법)

## 프로젝트 개요
**push_swap**: 두 개의 스택(`stack a`와 `stack b`)을 사용하는 정렬 알고리즘을 설계하고 최대한 적은 명령어를 사용해야 합니다.

**checker**: `push_swap`이 출력한 명령어 리스트를 입력으로 받아 해당 명령어가 주어진 정수 리스트를 올바르게 정렬했는지 검증하는 프로그램입니다.

## 명령어 종류
`push_swap`에서 사용할 수 있는 명령어는 다음과 같습니다:
  - `sa`: stack a의 상위 두 값을 교환.
  - `sb`: stack b의 상위 두 값을 교환.
  - `ss`: `sa`와 `sb`를 동시에 실행.
  - `pa`: stack b에서 stack a로 상위 값을 이동.
  - `pb`: stack a에서 stack b로 상위 값을 이동.
  - `ra`: stack a를 위로 회전(top을 bottom으로 이동).
  - `rb`: stack b를 위로 회전(top을 bottom으로 이동).
  - `rr`: `ra`와 `rb`를 동시에 실행.
  - `rra`: stack a를 아래로 회전(bottom을 top으로 이동).
  - `rrb`: stack b를 아래로 회전(bottom을 top으로 이동).
  - `rrr`: `rra`와 `rrb`를 동시에 실행.

## 학습 목표

1. **자료구조와 알고리즘**:
   - 스택 자료구조를 활용하여 정렬을 수행하는 방법을 학습합니다.
   - 정렬 알고리즘(예: 퀵소트, 병합 정렬)의 응용 및 최적화를 경험합니다.

2. **최적화**:
   - 명령어 사용 횟수를 최소화하기 위해 그리디 알고리즘을 사용합니다.

3. **표준 입력 처리**:
   - `checker` 프로그램을 통해 표준 입력으로 명령어 리스트를 실시간으로 처리하는 방법을 익힙니다.

4. **Error 처리**:
   - 잘못된 입력, 중복된 숫자, 정수 범위를 초과하는 값 등에 대해 적절히 에러를 처리하는 방법을 학습합니다.

## 파일 구조

```plaintext
so_long/
├── gnl/
├── libf/
├── bonus/                # checker에 대한 소스코드
├── src/                  # push_swap에 대한 소스코드
│   ├── command.c
│   ├── exec.c
│   ├── stack.c
│   ├── greedy_sort.c
│   ├── ...
│   ├── main.c
│   └── push_swap.h
└── Makefile
```

## 사용 방법

### push_swap 사용 예시

1. 컴파일:
   ```bash
   make
   ```
   `push_swap`이라는 이름의 실행파일이 생성됩니다.
2. 실행:
   정렬 하고자 하는 정수 배열을 실행 인자로 전달합니다.
   ```bash
   ./push_swap 4 1 3 2
   ```
   ```bash
   ARG="4 1 3 2"; ./push_swap $ARG
   ```

3. 명령어 예시:
   ```bash
   ra
   pb
   sa
   pa
   ```
### checker 사용 예시

1. 컴파일:
   ```bash
   make bonus
   ```
   `checker`라는 이름의 실행파일이 생성됩니다.
2. 실행:
   정렬 하고자 하는 정수 배열을 실행 인자로 전달합니다.
   실행 후 표준 입력으로 명령어를 입력합니다. 각 명령어는 '\n'으로 구분됩니다. 파이프라인(|)을 통해서 바로 인자로 전달도 가능합니다.
   ```bash
   ARG="4 1 3 2"; ./push_swap $ARG | ./checker $ARG
   ```
   - 결과:
     - `OK`: 정렬 성공.
     - `KO`: 정렬 실패.
     - `Error`: 잘못된 입력.

> **전체 과제에 대한 설명은 [push_swap](https://guiltless-break-8cc.notion.site/push_swap-ad66e4d7b2584ef0a86201ea4f12cede?pvs=4)를 참고하세요.**