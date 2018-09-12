/*
 求子数组的最大和
 题目：
 输入一个整形数组，数组里有正数也有负数。
 数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
 求所有子数组的和的最大值。要求时间复杂度为O(n)。
 例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，
 因此输出为该子数组的和18。
 */

/*
 总结：
 和最大的子序列的第一个元素肯定是正数
 因为元素有正有负，因此子序列的最大和一定大于0
 
 如果一段子数组的和<0,那么这段子数组就可以抛弃掉，从下一个数开始重新计算。
 */


/*
 变异问题： 求子数组的最大和所在的子数组。
 思路： 可不可以在算最大和的时候，保存一下开始的下表和结束的下表。
 */

#import <stdio.h>

int getMaxSubArraySum(int a[],int size) {
    if (size < 0) printf("size 传入错误");
    int maxNum = 0;
    int sum;
    int currentIndex = 0;
    
    int startIndex = 0;
    int stopIndex = 0;
    while (currentIndex < size) {
        sum += a[currentIndex];
        if(sum > maxNum) {
            maxNum = sum;
        } else if (sum < 0) {
            sum = 0;
        }
        
        currentIndex += 1;
    }
    
    return maxNum;
}

void getMaxSumSubArray(int a[], int size) {
    if (size < 0) printf("size 传入错误");
    int maxNum = 0;
    int sum;
    int currentIndex = 0;
    
    int startIndex = 0;
    int stopIndex = 0;
    
    for (currentIndex = 0; currentIndex < size ; currentIndex++) {
        sum += a[currentIndex];
        if(sum >= maxNum) {  // 说明当前a[current] 为正数，且如果这个点之前为负数，那么新的和也会变大
            maxNum = sum;
            
            //确定起始点：sum在没有加a[currentIndex] 之前是0
            if (sum == a[currentIndex]) {
                startIndex = currentIndex;
                printf("startIndex +++ %d\n",startIndex);
            }
            
            // 更新结束点,每走一个正数节点都当做结束点，当时负数节点时不更新结束节点
            stopIndex = currentIndex;
            printf("stopIndex +++ %d\n",stopIndex);
        } else  if (sum < 0) {  // 说明当前a[current] 为负数，那么最大和子数组为start 一直到 current - 1 这一段。
                sum = 0;
        }
    }


     printf("startIndex ==== %d\n",startIndex);
     printf("stopIndex  ==== %d\n",stopIndex);
     printf("maxnum     ==== %d\n",maxNum);
    // 子数组从startIndex 到stopIndex
    
    int i ;
    for (i = startIndex; i <= stopIndex;i++) {
        printf("%d\n",a[i]);
    }
    
    
}

int main () {
    int a[9] = {1, -2, 3, 10, -4, 7, 2,-5,8};
    int maxNum =  getMaxSubArraySum(a,9);
    printf("maxNum ==== %d\n",maxNum);
    
    getMaxSumSubArray(a,9);

    return 0;
}
