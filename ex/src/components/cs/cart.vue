<template>
    <div v-show='list.length!=0'>
        <div v-for="(item,index) of list" :key='index'>
            <input type="checkbox" v-model="item.isChecked">
            <img :src="`http://127.0.0.1:3000/${item.img}`" alt="">
            <button>删除</button>
        </div> 
        <input type="checkbox">全选

    </div>
</template>
<script>
export default {
    data(){
        return{
           list:[]
        }
    },
    created(){
        this.loadMore()
    },
    methods:{
        loadMore(){
            this.axios.get('cart').then(result=>{
                console.log(result.data)
                if(result.data.code==1){
                var list=result.data.data
                for(var item of list){
                    item.isChecked=true
                 };
                this.list=list
                }
            })
        }
    }
}
</script>


