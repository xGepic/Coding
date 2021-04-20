var para = document.createElement("p");
var spa = document.createElement("span");
spa.setAttribute("class", "output-browser");
para.appendChild(spa);
document.body.appendChild(para);

var userAgentString = navigator.userAgent;
var chromeAgent = userAgentString.indexOf("Chrome") > -1;
var IExplorerAgent = userAgentString.indexOf("MSIE") > -1;
var edgeAgent = userAgentString.indexOf("Edg") > -1;
var firefoxAgent = userAgentString.indexOf("Firefox") > -1;
var safariAgent = userAgentString.indexOf("Safari") > -1;

if ((chromeAgent) && (safariAgent))
    safariAgent = false;

var operaAgent = userAgentString.indexOf("OP") > -1;

if ((chromeAgent) && (operaAgent))
    chromeAgent = false;

if ((chromeAgent) && (edgeAgent))
    chromeAgent = false;

var usedBrowsers = [
    { name: "Chrome", isUsed: chromeAgent },
    { name: "MSIE", isUsed: IExplorerAgent },
    { name: "Edge", isUsed: edgeAgent },
    { name: "Firefox", isUsed: firefoxAgent },
    { name: "Safari", isUsed: safariAgent },
    { name: "OP", isUsed: operaAgent },
];

outputUsedBrowser();
function outputUsedBrowser() {
    for (var _i = 0, usedBrowsers_1 = usedBrowsers; _i < usedBrowsers_1.length; _i++) {
        var usedBrowser = usedBrowsers_1[_i];
        if (usedBrowser.isUsed) {
            document.querySelector(".output-browser").textContent = "Your Browser is: " + usedBrowser.name;
            break;
        }
    }
}

var riddle = document.createElement("div");
riddle.id = "riddle";
document.body.appendChild(riddle);

var puzzlePartsIdx = shufflePuzzleParts();
var _loop_1 = function (i) {
    var img = document.createElement("img");
    var imgId = "part" + puzzlePartsIdx[i];
    img.setAttribute("src", "img/img" + puzzlePartsIdx[i] + ".jpg");
    img.setAttribute("alt", imgId);
    img.setAttribute("id", imgId);
    img.addEventListener("click", function () {
        var currentImgId = img.getAttribute("id");
        var imgElement = document.getElementById(currentImgId);
        if (!isSolved()) {
            if (isSelectable()) {
                var firstSelectedPuzzlePartId = getAlreadySelectedPicId();
                imgElement.style.opacity = "1.0";
                if (imgElement.style.opacity != "0.6") {
                    imgElement.style.opacity = "0.6";
                }
                if (countSelected() > 1) {
                    if (areNeighbours(firstSelectedPuzzlePartId, currentImgId)) {
                        swapParts();
                    }
                    resetOpacity();
                }
            }
        }
    });
    riddle.appendChild(img);
};

for (var i = 0; i < puzzlePartsIdx.length; i++) {
    _loop_1(i);
}
function isSelectable() {
    return countSelected() <= 1;
}
function countSelected() {
    var pics = riddle.getElementsByTagName("img");
    var counter = 0;
    for (var i = 0; i < pics.length; i++) {
        if (pics[i].style.opacity == "0.6") {
            counter++;
        }
    }
    return counter;
}
function getAlreadySelectedPicId() {
    var pics = riddle.getElementsByTagName("img");
    var counter = 0;
    for (var i = 0; i < pics.length; i++) {
        if (pics[i].style.opacity == "0.6") {
            return pics[i].getAttribute("id");
        }
    }
    return "";
}
function isSolved() {
    var pics = riddle.getElementsByTagName("img");
    for (var i = 0; i < pics.length; i++) {
        var pic = "part" + (i + 1).toString();
        var element = pics[i].getAttribute("id");
        if (pic != element) {
            return false;
        }
    }
    return true;
}
function shufflePuzzleParts() {
    var puzzleParts = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    var counter = puzzleParts.length;
    while (counter > 0) {
        var index = Math.floor(Math.random() * counter);
        counter--;
        var temp = puzzleParts[counter];
        puzzleParts[counter] = puzzleParts[index];
        puzzleParts[index] = temp;
    }
    return puzzleParts;
}
function areNeighbours(firstPicId, secondPicId) {
    var pics = riddle.getElementsByTagName("img");
    for (var i = 0; i < pics.length; i++) {
        if (pics[i].getAttribute("id") == firstPicId) {
            var neighbourIdxs = getNeighbourIdxs(i);
            for (var j = 0; j < neighbourIdxs.length; j++) {
                if (pics[neighbourIdxs[j]].getAttribute("id") == secondPicId) {
                    return true;
                }
            }
        }
    }
    return false;
}
function swapParts() {
    var pics = riddle.getElementsByTagName("img");
    var pic1 = null;
    for (var i = 0; i < pics.length; i++) {
        if (pics[i].style.opacity == "0.6") {
            if (pic1 == null) {
                pic1 = document.getElementById(pics[i].getAttribute("id"));
                continue;
            }
            var pic2 = document.getElementById(pics[i].getAttribute("id"));
            var pic1Source = pic1.getAttribute("src");
            var pic1Alt = pic1.getAttribute("alt");
            var pic1Id = pic1.getAttribute("id");
            var pic2Source = pic2.getAttribute("src");
            var pic2Alt = pic2.getAttribute("alt");
            var pic2Id = pic2.getAttribute("id");
            pic1.setAttribute("src", pic2Source);
            pic1.setAttribute("alt", pic2Alt);
            pic1.setAttribute("id", pic2Id);
            pic2.setAttribute("src", pic1Source);
            pic2.setAttribute("alt", pic1Alt);
            pic2.setAttribute("id", pic1Id);
            if (isSolved()) {
                var solved = document.createElement("div");
                solved.id = "solved";
                var linkText = document.createTextNode("SOLVED!");
                solved.appendChild(linkText);
                riddle.appendChild(solved);
            }
            break;
        }
    }
}
function resetOpacity() {
    var pics = riddle.getElementsByTagName("img");
    for (var i = 0; i < pics.length; i++) {
        if (pics[i].style.opacity == "0.6") {
            pics[i].style.opacity = "1.0";
        }
    }
}
function getNeighbourIdxs(currentIdx) {
    var returnIdxs = [];
    if (isNeighbourIndexCol(currentIdx - 3)) {
        returnIdxs.push(currentIdx - 3);
    }
    if (isNeighbourIndexRow(currentIdx, currentIdx + 1)) {
        returnIdxs.push(currentIdx + 1);
    }
    if (isNeighbourIndexCol(currentIdx + 3)) {
        returnIdxs.push(currentIdx + 3);
    }
    if (isNeighbourIndexRow(currentIdx, currentIdx - 1)) {
        returnIdxs.push(currentIdx - 1);
    }
    return returnIdxs;
}
function isNeighbourIndexRow(currentIdx, checkIdx) {
    return (Math.max(-1, checkIdx) > -1) &&
        (Math.min(9, checkIdx) < 9) &&
        (Math.floor(currentIdx / 3) == Math.floor(checkIdx / 3));
}
function isNeighbourIndexCol(checkIdx) {
    return (Math.max(-1, checkIdx) > -1) &&
        (Math.min(9, checkIdx) < 9);
}
