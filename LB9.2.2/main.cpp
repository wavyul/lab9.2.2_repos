#include <iostream>

// ������ ��� ��������� ���������� ��� �������� �������
#define ERROR_MSG(msg) std::cerr << "Error: " << msg << "\nFile: " << __FILE__ << "\nLine: " << __LINE__ << "\nDate: " << __DATE__ << "\nTime: " << __TIME__ << std::endl;

// ������ ��� ��������� ���������� ��� ����, ���, ���� �� ���������� ��������� C++
#define INFO_MSG() std::cout << "Compiled File: " << __FILE__ << "\nCompiled Date: " << __DATE__ << "\nCompiled Time: " << __TIME__ << "\nLine: " << __LINE__ << std::endl; \
if (__cplusplus >= 201103L) std::cout << "Conforms to C++11 or later: Yes" << std::endl; \
else std::cout << "Conforms to C++11 or later: No" << std::endl;

// #pragma ��� ������������ ���������� �������� ���������
#pragma message("This is a pragma message: Parameter passing is disabled!")

int main(int argc, char* argv[]) {
    INFO_MSG();

    if (argc < 2) {
        // ��������� ������ ��� ����������� ��� �������
        ERROR_MSG("Not enough parameters!");
    }
    else {
        std::cout << "Program executed with parameters." << std::endl;
    }

    return 0;
}
