// return index if search it , return -1 if no search
int linear_search(int *num,int length,int find){
	for(int i=0;i<length;++i){
		if(num[i]==find)
			return i;
	}
	return -1;
}
