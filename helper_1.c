#include "shell.h"

/**
 * releaseRecurrentData - Free fields needed in each loop.
 * @data: Struct of the program's data.
 */
void releaseRecurrentData(data_of_program *data)
{
	if (data->tokens)
		freeArrayOfPointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * releaseAllData - Free all fields of the data.
 * @data: Struct of the program's data.
 */
void releaseAllData(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	releaseRecurrentData(data);
	freeArrayOfPointers(data->env);
	freeArrayOfPointers(data->alias_list);
}

/**
 * freeArrayOfPointers - Free each pointer of an array of pointers and the array itself.
 * @array: Array of pointers.
 */
void freeArrayOfPointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}

