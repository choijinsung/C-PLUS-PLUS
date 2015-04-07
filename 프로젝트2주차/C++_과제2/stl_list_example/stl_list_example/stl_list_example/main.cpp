#include <iostream>
#include <list>           // STL이 제공하는 linked list
#include <algorithm>      // STL이 제공하는 각종 알고리즘

void main()
{
  std::list<int>            ls;     // 각 요소가 int인 링크트 리스트 ls 생성
  std::list<int>::iterator  it;     // 각 요소가 int인 링크트 리스트 방문자 it 생성
  
  /// 링크트 리시트 ls에 값을 대입
  ls.push_back(2);        // ls: 2 - (end)
  ls.push_back(1);        // ls: 2 - 1 - (end)
  ls.push_back(5);        // ls: 2 - 1 - 5 - (end)
  ls.push_back(0);        // ls: 2 - 1 - 5 - 0 - (end)
  ls.push_front(9);       // ls: 9 - 2 - 1 - 5 - 0 - (end)
  ls.push_front(7);       // ls: 7 - 9 - 2 - 1 - 5 - 0 - (end)

  /// 방문자 it를 이용하여 링크트 리스트 ls 방문하고 내용을 화면에 찍기
  for (it = ls.begin(); it != ls.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
    
  /// 링크트 리스트 ls에서 특정값(5)을 찾아 삭제
  for (it = ls.begin(); it != ls.end(); ++it)
  {
    if (*it == 5)
    {
      ls.erase(it);
      break;
    }
  }

  /// 방문자 it를 이용하여 링크트 리스트 ls 방문하고 내용을 화면에 찍기
  for (it = ls.begin(); it != ls.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;



  /// 링크트 리스트 ls에서 특정값(2)을 찾아, 바로 앞의 값과 위치 바꾸기
  std::list<int>::iterator  loc, prev_loc;    // 링크트 리스트에서 각 요소의 위치를 저장할 수 있는 변수 loc, prev_loc 선언
  loc = std::find(ls.begin(), ls.end(), 2);   // 링크트 리스트 ls의 처음(begin())부터 끝(end()) 검색하며 2가 들어있는 곳의 위치를 loc에 대입
  if (loc != ls.begin())                      // loc가 링크트 리스트의 최초 요소의 위치가 아니라면...
  {
      prev_loc = loc; --prev_loc;             // loc의 앞인 prev_loc 계산
      ls.splice(prev_loc, ls, loc);           // loc에 있는 값을 때내어 prev_loc의 앞에 삽입
  }

  /// 방문자 it를 이용하여 링크트 리스트 ls 방문하고 내용을 화면에 찍기
  for (it = ls.begin(); it != ls.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  
  /// 링크트 리스트 ls에서 특정값(1)을 찾아, 바로 뒤의 값과 위치 바꾸기
  std::list<int>::iterator  next_loc;         // 링크트 리스트에서 각 요소의 위치를 저장할 수 있는 변수 loc, prev_loc 선언
  loc = std::find(ls.begin(), ls.end(), 1);   // 링크트 리스트 ls의 처음(begin())부터 끝(end()) 검색하며 5가 들어있는 곳의 위치를 loc에 대입
  next_loc = loc;     ++next_loc;             // loc위 뒤인 next_loc 계산
  if (next_loc != ls.end())                   // loc가 링크트 리스트의 마지막 요소의 위치가 아니라면... (next_loc가 end와 같지 않으면...)
  {      
      ls.splice(loc, ls, next_loc);           // next_loc에 있는 값을 때내어 loc의 앞에 삽입
  }

  /// 방문자 it를 이용하여 링크트 리스트 ls 방문하고 내용을 화면에 찍기
  for (it = ls.begin(); it != ls.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}