#include <fstream>
#include <filesystem>

int main(int, char* argv[]) {
    std::filesystem::path input{argv[1]};
    std::filesystem::path output{argv[2]};
    std::ifstream in{input};
    std::ofstream out{output, std::ios::trunc};
    out << in.rdbuf();
}
