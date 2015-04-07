#include <iostream>
#include <list>           // STL�� �����ϴ� linked list
#include <algorithm>      // STL�� �����ϴ� ���� �˰���

void main()
{
  std::list<int>            ls;     // �� ��Ұ� int�� ��ũƮ ����Ʈ ls ����
  std::list<int>::iterator  it;     // �� ��Ұ� int�� ��ũƮ ����Ʈ �湮�� it ����
  
  /// ��ũƮ ����Ʈ ls�� ���� ����
  ls.push_back(2);        // ls: 2 - (end)
  ls.push_back(1);        // ls: 2 - 1 - (end)
  ls.push_back(5);        // ls: 2 - 1 - 5 - (end)
  ls.push_back(0);        // ls: 2 - 1 - 5 - 0 - (end)
  ls.push_front(9);       // ls: 9 - 2 - 1 - 5 - 0 - (end)
  ls.push_front(7);       // ls: 7 - 9 - 2 - 1 - 5 - 0 - (end)

  /// �湮�� it�� �̿��Ͽ� ��ũƮ ����Ʈ ls �湮�ϰ� ������ ȭ�鿡 ���
  for (it = ls.begin(); it != ls.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
    
  /// ��ũƮ ����Ʈ ls���� Ư����(5)�� ã�� ����
  for (it = ls.begin(); it != ls.end(); ++it)
  {
    if (*it == 5)
    {
      ls.erase(it);
      break;
    }
  }

  /// �湮�� it�� �̿��Ͽ� ��ũƮ ����Ʈ ls �湮�ϰ� ������ ȭ�鿡 ���
  for (it = ls.begin(); it != ls.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;



  /// ��ũƮ ����Ʈ ls���� Ư����(2)�� ã��, �ٷ� ���� ���� ��ġ �ٲٱ�
  std::list<int>::iterator  loc, prev_loc;    // ��ũƮ ����Ʈ���� �� ����� ��ġ�� ������ �� �ִ� ���� loc, prev_loc ����
  loc = std::find(ls.begin(), ls.end(), 2);   // ��ũƮ ����Ʈ ls�� ó��(begin())���� ��(end()) �˻��ϸ� 2�� ����ִ� ���� ��ġ�� loc�� ����
  if (loc != ls.begin())                      // loc�� ��ũƮ ����Ʈ�� ���� ����� ��ġ�� �ƴ϶��...
  {
      prev_loc = loc; --prev_loc;             // loc�� ���� prev_loc ���
      ls.splice(prev_loc, ls, loc);           // loc�� �ִ� ���� ������ prev_loc�� �տ� ����
  }

  /// �湮�� it�� �̿��Ͽ� ��ũƮ ����Ʈ ls �湮�ϰ� ������ ȭ�鿡 ���
  for (it = ls.begin(); it != ls.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  
  /// ��ũƮ ����Ʈ ls���� Ư����(1)�� ã��, �ٷ� ���� ���� ��ġ �ٲٱ�
  std::list<int>::iterator  next_loc;         // ��ũƮ ����Ʈ���� �� ����� ��ġ�� ������ �� �ִ� ���� loc, prev_loc ����
  loc = std::find(ls.begin(), ls.end(), 1);   // ��ũƮ ����Ʈ ls�� ó��(begin())���� ��(end()) �˻��ϸ� 5�� ����ִ� ���� ��ġ�� loc�� ����
  next_loc = loc;     ++next_loc;             // loc�� ���� next_loc ���
  if (next_loc != ls.end())                   // loc�� ��ũƮ ����Ʈ�� ������ ����� ��ġ�� �ƴ϶��... (next_loc�� end�� ���� ������...)
  {      
      ls.splice(loc, ls, next_loc);           // next_loc�� �ִ� ���� ������ loc�� �տ� ����
  }

  /// �湮�� it�� �̿��Ͽ� ��ũƮ ����Ʈ ls �湮�ϰ� ������ ȭ�鿡 ���
  for (it = ls.begin(); it != ls.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}