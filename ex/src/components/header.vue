<template>
    <h2 >11{{msg}}</h2>
</template>
<script>
export default {
    data(){
        return{
        
        }
    },
    props:['msg'],
    created(){
        this.$emit('myEvent',345)
    }
}
</script>

