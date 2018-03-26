/* Original File copied from https://github.com/spacehuhn/esp8266_deauther */
var timezoneshift = getE('timezoneshift');
var earliestallowed = getE('earliestallowed');
var latestallowed = getE('latestallowed');
var res;

function getData() {
    getResponse("timesettings.json", function(responseText) {
        try {
            res = JSON.parse(responseText);
        } catch(e) {
            showMessage("Error: reset the timesettings.");
            return;
        }
        timezoneshift.value = res.timezoneshift;
        earliestallowed.value = res.earliestallowed;
        latestallowed.value = res.latestallowed;
    });
}

function savetimesettings() {
    saved.innerHTML = "saving...";
    var url = "timesettingsSave.json";
    url += "?timezoneshift=" + timezoneshift.value;
    url += "&earliestallowed=" + earliestallowed.value;
    url += "&latestallowed=" + latestallowed.value;

    getResponse(url, function(responseText) {
        if (responseText == "true") {
            getData();
            saved.innerHTML = "saved";
        }
        else showMessage("response error timesettingsSave.json");
    });
}

function resettimesettings() {
    getResponse("timesettingsReset.json", function(responseText) {
        if (responseText == "true") {
            getData();
            saved.innerHTML = "saved";
        }
        else showMessage("response error timesettingsReset.json");
    });
}

function restart(){
    getResponse("restartESP.json?", function(){});
}

getData();