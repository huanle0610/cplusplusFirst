#include <iostream> 
#include <string> 
using namespace std; 

struct task {
    task* pNext;
    string description;
};

task* pHead = nullptr;
task* pCurrent = nullptr;

void queue_task(const string& name)
{
    task* pTask = new task;
    pTask->description = name;
    pTask->pNext = nullptr;
    
    if(nullptr == pHead)
    {
        pHead = pTask;
        pCurrent = pTask;
    }
    else
    {
        pCurrent->pNext = pTask;
        pCurrent = pTask;
    }
}

bool remove_head()
{
    if(nullptr == pHead) return false;
    task* pTask = pHead;
    pHead = pHead->pNext;
    delete pTask;
    return (nullptr != pHead);
}

void destroy_list()
{
    while(remove_head());
}

task* execute_task(const task* pTask)
{
    if(nullptr == pTask) return nullptr;
    cout << "execute " << pTask->description << endl;
    return pTask->pNext;
}

void execute_all()
{
    task* pTask = pHead;
    while(pTask != nullptr)
    {
        pTask = execute_task(pTask);
    }
}

task* find_task(const string& name)
{
    task* pTask = pHead;
    while(nullptr != pTask)
    {
        if(name == pTask->description) return pTask;
        pTask = pTask->pNext;
    }
    
    return nullptr;
}

void insert_after(task* pTask, const string& name)
{
    task* pNewTask = new task;
    pNewTask->description = name;
    if(nullptr != pTask)
    {
        pNewTask->pNext = pTask->pNext;
        pTask->pNext = pNewTask;
    }
    else
    {
        pNewTask->pNext = pHead;
        pHead = pNewTask;
    }
}

int main(int argc, char **argv)
{
	cout << "amtf" << endl;
    
    queue_task("remove old wallpaper");
    queue_task("fill holes");
    queue_task("size walls");
    queue_task("hang new wallpaper");
    
    task* pTask = find_task("fill holes");
    if(nullptr != pTask)
    {
        insert_after(pTask, "paint woodwork");
    }
    
    insert_after(nullptr, "cover funiture");
    
    execute_all();
    destroy_list();
	return 0;
}
