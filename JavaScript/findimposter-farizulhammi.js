function findOutlier(integers) {
    var arrResult = []
    integers.forEach(data => {
        if (data % 2 == 0) {
            arrResult.push(true)
        } else {
            arrResult.push(false)
        }
    });
    const resEven = arrResult.filter(check => check == true).length;
    const resOdd = arrResult.filter(check => check == false).length;

    if (resEven > resOdd) {
        const index = arrResult.findIndex(data => data == false)
        return integers[index]
    } else {
        const index = arrResult.findIndex(data => data == true)
        return integers[index]
    }
}
