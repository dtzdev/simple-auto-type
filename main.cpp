#include <iostream>
#include <regex>
#include <string>
#include <Windows.h>

void type(const std::string& keys) {
    std::regex pattern("[a-zA-Z0-9]+");
    if (!std::regex_match(keys, pattern)) {
        std::cerr << "Only letters and numbers are allowed." << std::endl;
        return;
    }
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    for (char key : keys) {
        ip.ki.wVk = VkKeyScanA(key);
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(100);
    }
}

int main() {
    type("Hello World");
    return 0;
}
