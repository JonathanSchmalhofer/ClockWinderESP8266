/* Original File copied from https://github.com/spacehuhn/esp8266_deauther */
var firstwatchname = getE('firstwatchname');
var firstwatchturnsperday = getE('firstwatchturnsperday');
var firstwatchturndirection = getE('firstwatchturndirection');
var secondwatchname = getE('secondwatchname');
var secondwatchturnsperday = getE('secondwatchturnsperday');
var secondwatchturndirection = getE('secondwatchturndirection');
var thirdwatchname = getE('thirdwatchname');
var thirdwatchturnsperday = getE('thirdwatchturnsperday');
var thirdwatchturndirection = getE('thirdwatchturndirection');
var res;

function getData() {
    getResponse("watches.json", function(responseText) {
        try {
            res = JSON.parse(responseText);
        } catch(e) {
            showMessage("Error: reset the watches setting.");
            return;
        }
        firstwatchname.value = res.firstwatchname;
        firstwatchturnsperday.value = res.firstwatchturnsperday;
        firstwatchturndirection.value = res.firstwatchturndirection;
        secondwatchname.value = res.secondwatchname;
        secondwatchturnsperday.value = res.secondwatchturnsperday;
        secondwatchturndirection.value = res.secondwatchturndirection;
        thirdwatchname.value = res.thirdwatchname;
        thirdwatchturnsperday.value = res.thirdwatchturnsperday;
        thirdwatchturndirection.value = res.thirdwatchturndirection;
    });
}

function savewatches() {
    saved.innerHTML = "saving...";
    var url = "watchesSave.json";
    url += "?firstwatchname=" + firstwatchname.value;
    url += "&firstwatchturnsperday=" + firstwatchturnsperday.value;
    url += "&firstwatchturndirection=" + firstwatchturndirection.value;
    url += "&secondwatchname=" + secondwatchname.value;
    url += "&secondwatchturnsperday=" + secondwatchturnsperday.value;
    url += "&secondwatchturndirection=" + secondwatchturndirection.value;
    url += "&thirdwatchname=" + thirdwatchname.value;
    url += "&thirdwatchturnsperday=" + thirdwatchturnsperday.value;
    url += "&thirdwatchturndirection=" + thirdwatchturndirection.value;

    getResponse(url, function(responseText) {
        if (responseText == "true") {
            getData();
            saved.innerHTML = "saved";
        }
        else showMessage("response error watchesSave.json");
    });
}

function resetwatches() {
    getResponse("watchesReset.json", function(responseText) {
        if (responseText == "true") {
            getData();
            saved.innerHTML = "saved";
        }
        else showMessage("response error watchesReset.json");
    });
}

getData();