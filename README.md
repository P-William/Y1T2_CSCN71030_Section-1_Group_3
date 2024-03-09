# Y1T2_CSCN71030_Section-1_Group_3


### Conventions
- Variable and Function Naming - Camel Case
    - `int myNumber = 50`
    - `int getAge(Person person)`
- Constants - Upper Case (underscore seperated)
    - `#define TITLE_LENGTH 70`
    - `const int MAX_WIDTH 200`
- Typedef - Pascal Case
    - ```c
        typedef struct Person {
            int age;
            char name[MAX_NAME_LENGTH];
        } Person;
    - ```c
        typedef enum Day {
            MONDAY,
            TUESDAY,
            ETC
        } Day;
- File Names - Lower Case (underscore separated)
    - `my_file.c`
    - `user_input_handler.h`