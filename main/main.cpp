#include "../source/SplayTree_vs_BTree.cpp"
#include <chrono>
#include <ctime>


int main (int argc, char* argv[])
{
	Tree b_tree{1};
	SplayTree<int> splay_tree{1};
	srand(time(0));
	std::cout << "       !!!BTREE!!!" << std::endl;
	auto begin = std::chrono::steady_clock::now();
	for (int i=0; i<1000; i++)
	{
		b_tree.insert((int)(rand()));
	}
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "INSERT: " << elapsed_ms.count() << " ns" << std::endl;
	////////////////////////////////
	begin = std::chrono::steady_clock::now();
	for (int i=0; i<1000; i++)
 	{
 		b_tree.search((int)(rand()));
 	}       
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "SEARCH: " << elapsed_ms.count() << " ns" << std::endl;

	////////////////////////////////
	begin = std::chrono::steady_clock::now();
	for (int i=0; i<1000; i++)
 	{
 		b_tree.remove((int)(rand()));
 	}       
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "REMOVE: " << elapsed_ms.count() << " ns" << std::endl;
	////////////////////////////////
	std::cout << "    !!!SPLAY TREE!!!" << std::endl;
	begin = std::chrono::steady_clock::now();
	for (int i=0; i<1000; i++)
 	{
 		splay_tree.insert((int)(rand()));
 	}       
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "INSERT: " << elapsed_ms.count() << " ns" << std::endl;
	///////////////////////////////////
	begin = std::chrono::steady_clock::now();
	for (int i=0; i<1000; i++)
 	{
 		splay_tree.search((int)(rand()));
 	}       
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "SEARCH: " << elapsed_ms.count() << " ns" << std::endl;
	///////////////////////////////////
	begin = std::chrono::steady_clock::now();
	for (int i=0; i<1000; i++)
 	{
 		splay_tree.remove((int)(rand()));
 	}       
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "REMOVE: " << elapsed_ms.count() << " ns" << std::endl;
	return 0;
}
