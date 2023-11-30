#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{

    // TODO #1
    // Ensure proper

    if (argc != 3)
    {
        printf("Warning: Incorrect usage\n Try: Try: ./reverse input.wav output.wav\n");

        return 1;
    }

    // TODO #2
    // Open input file for reading
    char *inputFile = argv[1];
    FILE *givenAudio = fopen(inputFile, "rb");

    if (givenAudio == NULL)
    {
        printf("Error: File can't opened \n");
        return 1;
    }

    // TODO #3
    // Read header

    WAVHEADER audioHeader;
    fread(&audioHeader, sizeof(audioHeader), 1, givenAudio);

    // TODO #4
    // Use check_format to ensure WAV format

    if (!check_format(audioHeader))
    {

        printf("Error: Incorrect file format\n File format should be .wav\n");
        fclose(givenAudio);
        return 1;
    }

    // TODO #5
    // Open output file for writing

    char *outputFile = argv[2];
    FILE *reversedAudio = fopen(outputFile, "wb");

    if (reversedAudio == NULL)
    {
        printf("Error: Unable to create output file \n");
        fclose(reversedAudio);
        return 1;
    }

    // TODO #6
    // Write header to file

    fwrite(&audioHeader, sizeof(audioHeader), 1, reversedAudio);

    // TODO #7

    // Use get_block_size to calculate size of block

    int blockSize = get_block_size(audioHeader);

    // TODO #8
    // Write reversed audio to file

    // Step 1: Declare an array to store each block we read in
    BYTE audioData[blockSize];

    // Step 2: Declare the size of audio data

    int audioSize = audioHeader.subchunk2Size;

    // Step 3: Calculate quantity of the audio blocks

    int blocksNum = audioSize / blockSize;

    // Step 4: Get reversed audio

    // Iteration starts from the last audio block in the file and goes on through all audio blocks in reversed order,
    // from the last block to the first.

    for (int i = blocksNum - 1; i >= 0; i--)
    {

        // The file pointer is positioned at the beginning of the current audio block

        fseek(givenAudio, sizeof(audioHeader) + blockSize * i, SEEK_SET);

        // Read the audio data from the current block and write to another file. (The result is reversed audio file.)

        fread(audioData, 1, blockSize, givenAudio);
        fwrite(audioData, 1, blockSize, reversedAudio);
    }

    fclose(givenAudio);
    fclose(reversedAudio);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    char formatPattern[] = "WAVE";
    int patternLen = strlen(formatPattern);
    for (int i = 0; i < patternLen; i++)
    {
        if (header.format[i] != formatPattern[i])
        {
            return 0;
        }
    }

    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7

    return (header.numChannels * header.bitsPerSample) / 8; // Block size in bytes
}