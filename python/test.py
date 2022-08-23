from array import array


def bubble_sort(array):
    for i in range(1, len(array)):
        for j in range(0, len(array)-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array

if __name__ == '__main__':
    array = [6,7,9,8,4,2,1,3]
    print(bubble_sort(array))