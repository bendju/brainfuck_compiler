#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, char* argv[]) 
{
    int pointer = 0;
    std::vector<unsigned char> cells(30000, 0);

    std::ifstream file(argv[1]);
    char c;
    std::string code;
    while (file.get(c)) 
    {
        code += c;
    }
    file.close();


    for (int i = 0; i < code.size(); i++) 
    {
        switch (code[i]) 
        {
            case '>':
                if (pointer == 29999)
                {
                    break;
                }
                pointer++;
                break;
            case '<':
                if (pointer == 0)
                {
                    break;
                }
                pointer--;
                break;
            case '+':
                if (cells[pointer] == 255)
                {
                    cells[pointer] = 0;
                    break;
                }
                cells[pointer]++;
                break;
            case '-':
                if (cells[pointer] == 0)
                {
                    cells[pointer] = 255;
                    break;
                }
                cells[pointer]--;
                break;
            case '.':
                std::cout << static_cast<char>(cells[pointer]);
                break;
            case ',':
                std::cin >> cells[pointer];
                break;
            case '[':
                if (cells[pointer] == 0) 
                {
                    while (code[i] != ']') 
                    {
                        i++;
                    }
                }
                break;
            case ']':
                int loopCounter = 0;
                while (code[i] != '[') 
                {
                    i--;
                    loopCounter++;
                }
                if (cells[pointer] == 0)
                {
                    i += loopCounter;
                }
                break;
        }
    }
    std::cout << std::endl << std::endl << "The program ran successfully." << std::endl << std::endl;
    return 0;
}