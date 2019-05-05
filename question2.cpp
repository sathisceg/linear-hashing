#include <bits/stdc++.h>

using namespace std;

void display_buffer(map<int,vector<int> > hashBuffer)
{

			int i,j;
			for(i=0;i<hashBuffer.size();i++)
			{
				cout<<i<<"    ";
				for(j=0;j<hashBuffer[i].size();j++)
				{
					cout<<hashBuffer[i][j]<<" ";
				}

				cout<<endl;
			}
}

int main(int argc, char** argv)
{


	// cout << "You have entered " << argc
 //         << " arguments:" << "\n";
 
 //    for (int i = 1; i < argc; ++i)
 //        cout << argv[i] << "\n";

 //    cout<<atoi(argv[2])+atoi(argv[3]);

	FILE* fp;
	char buffer[255];

	int sum=0;

	fp = fopen(argv[1], "r");

	FILE *fptr;

    fptr = fopen("output.txt", "w");

	vector <int> num;
	vector<int> duplicates;

	while(fgets(buffer, 255, (FILE*) fp)) 
	{
  	  // printf("%s\n", buffer);
  	  num.push_back(atoi(buffer));
	}
	fclose(fp);


	int n=num.size();


	// for(int i=0;i<num.size();i++)
	// {
	// 	printf("%d \n",num[i] );
	// }

	
	int prev_hash_value=0;
	map<int,vector<int> > hashBuffer;

	int i=0,j=0;
	int number_of_elements=0;
	int number_of_linear_box=atoi(argv[2]);
	int current_hash_Value=number_of_linear_box;

	int buffer_size=atoi(argv[3]);
	int box_to_split=0;
	int split_condition=2;

	int flag=0;

	while(i<n)
	{

			number_of_elements++;
		
		
			int index = num[i]%current_hash_Value;


			
			// printf("number_of_elements :%d \n",number_of_elements);

			if(std::find(hashBuffer[index].begin(), hashBuffer[index].end(), num[i]) != hashBuffer[index].end())
			{
	  		    // cout<<"duplicate found :"<<num[i]<<endl;
	  		    duplicates.push_back(num[i]);
	  			i++;
	  			continue;
			} 
			else
			{
				hashBuffer[index].push_back(num[i]);
				//printf("			i1 %d %d\n",i,num[i]);

				if(number_of_elements>number_of_linear_box*buffer_size)
				{

						//printf("greater \n");
						number_of_linear_box++;

						if(flag==0)
						{
							prev_hash_value=current_hash_Value;
							current_hash_Value=2*prev_hash_value;
							flag=1;
						}


						// printf("current_hash_Value :%d  \n",current_hash_Value );
						// printf("prev_hash_value :%d  \n",prev_hash_value );

						// printf("box_to_split :%d \n",box_to_split );

						if(box_to_split==split_condition)
						{
							box_to_split=0;
							split_condition=2*split_condition;
							flag=0;
						}

						// cout<<"box_to_split :"<<box_to_split<<endl;
						// cout<<hashBuffer[box_to_split].size()<<endl;

						int temp_size = hashBuffer[box_to_split].size();
						for(j=0;j<temp_size;j++)
						{


							
							int val = hashBuffer[box_to_split][0];


							// printf("val :%d  \n",val);

							hashBuffer[box_to_split].erase (hashBuffer[box_to_split].begin()+0);


							
							// printf("hashBuffer[box_to_split][j] :%d  \n",hashBuffer[box_to_split][0]);
							// break;
							
							int index = val%current_hash_Value;
							// printf("index %d\n",index);
							
							
							// if(box_to_split==1)
							// 	printf("current_hash_Value :%d  \n",current_hash_Value );

							if(std::find(hashBuffer[index].begin(), hashBuffer[index].end(), val) != hashBuffer[index].end())
							{
	  		 						   // cout<<"duplicate found :"<<num[i]<<endl;
	  									// i++;
										duplicates.push_back(val);
	  									continue;
							} 

							hashBuffer[index].push_back(val);
					

							

							// if(j==10)
							// 	break;
						}
						//printf("\n");

						if(flag!=0)
						{
							box_to_split++;
						}
			

						
				}
				else
				{
						// hashBuffer[index].push_back(num[i]);
						// i++;
				}

				i++;
			
		}		
		 // cout<<"i "<<i-1<<endl;		
	}




	// printf("current_hash_Value :%d \n",current_hash_Value );

	// printf("\nmap size %d\n",hashBuffer.size() );

	// printf("\nkeys of map\n");

	// map<int,vector<int> >::iterator it;

	// for(it=hashBuffer.begin();it!=hashBuffer.end();it++)
	// {
	// 	printf("%d\n",it->first );
	// }




	// printf("\nelements in buffer \n");

	fprintf(fptr,"elements in buffer \n");

	for(i=0;i<hashBuffer.size();i++)
	{
		cout<<i<<"    ";
		fprintf(fptr,"%d  ",i);
		
		for(j=0;j<hashBuffer[i].size();j++)
		{
			cout<<hashBuffer[i][j]<<" ";

			fprintf(fptr,"%d ",hashBuffer[i][j]);
		}

		fprintf(fptr,"\n");
		cout<<endl;
	}



	fprintf(fptr,"\nDuplicates found \n");

	for(i=0;i<duplicates.size();i++)
	{
		fprintf(fptr,"%d ",duplicates[i]);
	}
	fprintf(fptr,"\n");


	fprintf(fptr,"\ncurrent_hash_Value %d \n\n",current_hash_Value);
	fprintf(fptr,"box_to_split %d ",box_to_split);
	// printf("current_hash_Value :%d \n",current_hash_Value );
	fclose(fptr);
	printf("\n");





	

	return 0;
}