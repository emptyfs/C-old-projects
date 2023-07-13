#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int useFile(char *filename, char *condition)
{
	FILE *current_file = fopen(filename, "r");
	char message[100];
	fgets(message, 100, current_file);
	char *flow;
	int add = 0;
	int mul = 1;	
	flow = strtok(message, " '\t''\n'");

    while(flow)
    {
		if(strcmp(condition, "add") == 0)
        {
            add = add + atoi(flow);
		}

		if(strcmp(condition, "mul") == 0)
        {
			mul = mul * atoi(flow);
		}

        flow = strtok(NULL, " '\t''\n'");
    }

	fclose(current_file);

	if(strcmp(condition, "add") == 0)
    {
	    return add;
	}

	if(strcmp(condition, "mul") == 0)
    {
	    return mul;
	}
}

int useDir(char *direction, char *condition, int *outcome)
{
	char direction_tmp[300] = "";
	strcpy(direction_tmp, direction);
	DIR *dir = opendir(direction);
	struct dirent *de = readdir(dir);

	while(de)
    {
		while(de && strcmp(de->d_name, ".") && strcmp(de->d_name, ".."))
        {	
			if(de->d_type == DT_DIR)
            {
				int count = 0;

				if(strcmp(de->d_name, "mul") == 0)
                {
				    count = 1;	
				}

				int len = strlen(direction_tmp);
				strcat(direction_tmp, "/");
				strcat(direction_tmp,de->d_name);

				if(strcmp(condition, "add") == 0)
                {
				    *outcome = *outcome + useDir(direction_tmp, de->d_name, &count);
				}

				if(strcmp(condition, "mul") == 0)
                {
				    *outcome = *outcome * useDir(direction_tmp, de->d_name, &count);
				}

				direction_tmp[len] = '\0';
			}
			if (de->d_type == DT_REG)
            {		
				int len = strlen(direction_tmp);	
				strcat(direction_tmp, "/");
				strcat(direction_tmp,de->d_name);

				if(strcmp(condition, "add") == 0)
                {
				    *outcome = *outcome + useFile(direction_tmp, condition);
				}

				if(strcmp(condition, "mul") == 0)
                {
				    *outcome = *outcome * useFile(direction_tmp, condition);
				}

				direction_tmp[len] = '\0';
			}
			de = readdir(dir);
		}
		de = readdir(dir);	
	}
	closedir(dir);
	return *outcome; 
}

int main()
{
	char direction[10000] = "./tmp";
	DIR *dir = opendir(direction);
	struct dirent *de;
	de = readdir(dir);

	while(strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
    {
		de = readdir(dir);
	}

	FILE *result = fopen("result.txt", "w"); 
	int outcome = 0;

	if(strcmp(de->d_name, "mul") == 0)
    {
	    outcome = 1;
	}
    
	fprintf(result, "%d\n", useDir(direction, de->d_name, &outcome));
	fclose(result);
	closedir(dir);
	return 0;
}
