#include <SplayTree.cpp>
#include <BTree.hpp>
#include <chrono>

bool unspec(int cor2, std::ofstream& fout)
{
    if (cor2 == 0)
    {
        fout << "Tree type wasn't specified!" << std::endl;
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return 0;
    }

    std::string name_input = "../tests/";
    name_input += argv[1];

    std::ifstream file_input(name_input);
    if (!file_input.is_open())
    {
        std::cout << "File " << argv[1] << "doesn't exist" << std::endl;
        return 0;
    }

    std::string name_output = "../tests/";
    name_output += argv[2];

    std::ofstream file_output(name_output);

    std::string command;
    int key;
    int data;
    int type = 0;

    SplayTree<int> STree;
    Tree BTree;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    while (file_input >> command)
    {
        if (command == "splay")
            type = 1;
        else if (command == "b")
            type = 2;
        else if (command == "insert")
        {
            if (unspec(type, file_output)) return 0;
            file_input >> key;
            file_input >> data;
            if (type == 1)
            {
                STree.insert(key, data);
            }
            if (type == 2)
            {
                BTree.insert(key, data);
            }
        }
        else if (command == "print")
        {
            if (unspec(type, file_output)) return 0;
            if (type == 1)
                STree.print(file_output, STree.root_, 0);
            if (type == 2)
                BTree.print(file_output, BTree.root, 0);
        }
        else if (command == "min")
        {
            if (unspec(type, file_output)) return 0;
            if (type == 1)
                file_output << *STree.min() << std::endl;
            if (type == 2)
                file_output << BTree.min(BTree.root) << std::endl;
        }
        else if (command == "max")
        {
            if (unspec(type, file_output)) return 0;
            if (type == 1)
                file_output << *STree.max() << std::endl;
            if (type == 2)
                file_output << BTree.max(BTree.root) << std::endl;
        }
        else if (command == "find")
        {
            if (unspec(type, file_output)) return 0;
            file_input >> key;
            if (type == 1)
            {
                if (STree.search(key))
                    file_output << "Found: " << *STree.search(key) << std::endl;
                else
                    file_output << "Key not found!" << std::endl;
            }
            if (type == 2)
            {
                if (BTree.search(key))
                    file_output << "Found: " << *BTree.search(key) << std::endl;
                else
                    file_output << "Key not found!" << std::endl;
            }
        }
        else if (command == "delete")
        {
            if (unspec(type, file_output)) return 0;
            file_input >> key;
            if (type == 1)
            {
                if (STree.search(key))
                {
                    STree.remove(key);
                    file_output << key << " removed successfully" << std::endl;
                }
                else
                    file_output << "There is no node with such key!" << std::endl;
            }
            if (type == 2)
            {
                if (BTree.search(key))
                {
                    BTree.remove(key);
                    file_output << key << " removed successfully" << std::endl;
                }
                else
                    file_output << "There is no node with such key!" << std::endl;
            }
        }

        else
            file_output << "Unknown command!" << std::endl;
    }

    end = std::chrono::system_clock::now();
    long elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

    file_output << "Runtime: " << elapsed_seconds << "us" << std::endl;

    file_input.close();
    file_output.close();

    return 0;
}
