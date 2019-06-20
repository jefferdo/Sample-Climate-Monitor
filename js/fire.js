$(document).ready(function () {
    refresh();
    function refresh() {
        $.ajax({
            type: 'get',
            url: '/getData.php',
            dataType: 'json',
            success: function (data) {
                $('#temp').html(data['temp']);
                $('#humid').html(data['humid']);
                $('#name').html(data['nodeName']);
                refresh();
            },
            error: function (e) {
                $('#name').html(e);
                refresh();
            }
        });
    }
});