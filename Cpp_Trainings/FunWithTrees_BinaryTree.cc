/*
CODEWARS - Estudo de Solução
http://www.codewars.com/kata/57e5a6a67fbcc9ba900021cd

"Fun with trees: array to tree"
*/

#include <iostream>
#include <vector>
#include <string>

class TreeNode {
public:
    int m_value;
    TreeNode * m_left, * m_right;
    TreeNode(int value, TreeNode * left, TreeNode * right):
      m_value(value), m_left(left), m_right(right){};
    TreeNode(int value):m_value(value), m_left(NULL), m_right(NULL){};
    ~TreeNode(){};
};

class Solution
{
  public:
    static TreeNode* arrayToTree(std::vector<int> arr) 
    {
    	TreeNode** node;
    	int size = arr.size();
		if (arr.empty())
			return NULL;
		if (size == 1)
			return new TreeNode(arr[0]);

		node = new TreeNode*[size];	// "Array" de TreeNode => Árvore
		// Cria os nós folhas
		for (int i = size - 1; i > size / 2 - 1; --i)
			node[i] = new TreeNode(arr[i]);
		// Cria os nós internos e liga aos nós folha
		for (int i= size / 2 - 1; i >= 0; --i)
			node[i] = new TreeNode(arr[i], node[2 * i + 1], node[2 * i + 2]);
		return node[0];
    }

    // Exibe Árvore na notação de parênteses
    static std::string stringTree(TreeNode* tree, std::string &sTree)
	{
		// Percurso da esquerda para a direita
		if (tree != NULL){
			sTree += "(" + std::to_string(tree->m_value);
			if (tree->m_left != NULL)
				stringTree(tree->m_left, sTree);
			if (tree->m_right != NULL)
				stringTree(tree->m_right, sTree);
			sTree += ")";
		} else
			return "null";
		return sTree;
	}
};

// Testes
void testequal(TreeNode* treeAns, TreeNode* treeSol) {
	std::string ans, sol;
	ans = Solution::stringTree (treeAns, ans);
	sol = Solution::stringTree (treeSol, sol);
    std::cout << "ans) " << ans << "\nsol) " << sol << "\nans = sol: ";
	std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    std::vector<int> arr;
    TreeNode* expected;

    arr = {};
    expected = NULL;
    testequal(Solution::arrayToTree(arr), expected);

    arr = {17, 0, -4, 3, 15};
    expected = new TreeNode(17, new TreeNode(0, new TreeNode(3),
    	new TreeNode(15)), new TreeNode(-4));
    testequal(Solution::arrayToTree(arr), expected);

    arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    expected = new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(8),
     new TreeNode(9)), new TreeNode(5, new TreeNode(10), NULL)), new TreeNode(3,
     new TreeNode(6), new TreeNode(7)));
    testequal(Solution::arrayToTree(arr), expected);

  return 0;
}