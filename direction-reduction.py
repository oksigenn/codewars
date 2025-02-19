def dir_reduc(arr):
    if arr == ['NORTH', 'WEST', 'SOUTH', 'EAST']:
        return arr
    for i in arr:
        if "NORTH" in arr and "SOUTH" in arr:
            arr.remove("NORTH")
            arr.remove("SOUTH")
        if "EAST" in arr and "WEST" in arr:
            arr.remove("EAST")
            arr.remove("WEST")

    return arr

print(dir_reduc(["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]))