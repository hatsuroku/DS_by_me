int count = 0;


void dfs(int x,int deep,int sum) {
	for(int i=x+1; i<arr.length(); i++) {
		if(deep==4) {
			// deep = k就是循环的第k层应该做什么
			count++;
			System.out.println(sum+arr[i]);
		} else {
			// do something
			
			// 进入下一层
			// 下一层没有上一层的任何信息
			// 如果需要隔层传递信息则需要利用参数传入
			dfs(i,deep+1,sum+arr[i]);
			// 如果对参数做了什么修改，则需要在这里改回来
			// 以免影响下一个同层循环
		}
	}
}

void solve(){
	dfs(-1,0,0);
	System.out.println(count); 
}