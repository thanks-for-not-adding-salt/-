//key,right,left
//从右往左找小数 从左往右找大数 交换位置
//递归操作

//交换位置函数
void swap(int*a,int*b)//一个函数要声明类型
{
 int tmp= *a;//这一行创建了一个临时变量 tmp 并将 a 指针指向的值赋给它
 *a =*b;
 *b =tmp;
}
//实现从left->right 区间的排序
  int partsort(int*a,int left,int right)//函数类型与返回值有关
  {
       int key =left;
       while(left<right)//这里是left而不是a[left]  当left，right相等时结束循环，此时key值被放到了正确的位置上
        {
          while (left<right&&a[right]>=a[key])
          {
                right--;            
          }
          while(a[left]<=a[key])
          {
                 left++;
          }

        }
       swap(&a[key],&a[right]);
       return right；//返回right
  }

  void quicksort(int*a,int begin,int end)//接受三个参数，指针类型的a，begin，end
  {
     if(begin >= end)
     {
        return;
     }
     int keyi = partsort(a, begin, end);//keyi=right
		//排一次，分为三个区间  [begin,key-1] key [key+1,end]
	quicksort(a,  begin, keyi-1);//左到right-1 即是第一个数到正确排列的数左边一个数
	quicksort( a, keyi+1, end);
  }